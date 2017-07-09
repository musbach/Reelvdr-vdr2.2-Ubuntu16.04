/**
 * @file manager.cpp
 * @author Michael Vogt <mvo@debian.org>
 * @author Peter Rockai <me@mornfall.net>
 */

#include <apt-pkg/error.h>
#include <apt-pkg/configuration.h>
#include <apt-pkg/sourcelist.h>
#include <apt-pkg/pkgsystem.h>
#include <apt-pkg/acquire.h>
#include <apt-pkg/acquire-item.h>
#include <libintl.h>

// FIXME: we need gettext support
#define _(x) x

#include <apt-front/error.h>
#include <apt-front/manager.h>
#include <apt-front/progresscallback.h>
#include <apt-front/cache/cache.h>
#include <apt-front/cache/component/state.h>
#include <apt-front/utils/shared.h>

using namespace aptFront;

Manager::Manager(cache::Cache *c) 
    : m_cache(0), m_progress(0), m_updateInterval( 200000 ), m_pm( 0 ),
      m_fetcher( 0 )
{
   m_cache = c;
}

Manager::~Manager() {
    delete m_pm;
    delete m_fetcher;
}

void Manager::setProgressCallback(SharedPtr<ProgressCallback> progress)
{
   m_progress = progress;
}

void Manager::download()
{
    // for some reason, if this throws, a subsequent update
    // will fail to grab lock on the lists directory
    // WEIRD
    cache::Cache &c = cache::Global::get( m_cache );
    if (c.state().brokenCount() != 0)
        throw exception::Error( "Can't download/commit with broken packages." );

    createFetcher();
    m_pm = _system->CreatePM(&c.state().baseReference());
    getArchives();
}

void Manager::getArchives()
{
    if (!m_pm)
        throw exception::InternalError( "Tried to get archives without PM" );
    if (!m_fetcher)
        throw exception::InternalError( "Tried to get archives without fetcher" );

    cache::Cache &c = cache::Global::get( m_cache );

    m_fetcher->Shutdown(); // reload

    pkgSourceList SList;

    // FIXME: we really need an apt-front sources list class that'd be
    // safe (that is, throw exceptions itself)
    if(!SList.ReadMainList())
        throw exception::Error( "The list of sources could not be read.");
    pkgRecords *r = new pkgRecords( c.packages().baseReference() );
    m_pm->GetArchives( m_fetcher, &SList, r );
    delete r;

    fetch();
}

void Manager::fetch() {

    if (!m_fetcher)
        throw exception::InternalError( "Tried to fetch without fetcher" );

    pkgAcquire::RunResult res = m_fetcher->Run( m_updateInterval );
    if( res == pkgAcquire::Failed )
        throw exception::Error( "Download failed" );

    if( res == pkgAcquire::Cancelled )
        throw exception::OperationCancelled();
}

void Manager::createFetcher() {
    if (m_progress.data() == 0) {
        throw exception::InternalError(
            "Manager: createFetcher called without progress object");
    }
    m_fetcher = new pkgAcquire( m_progress.data() );
}

void Manager::commit()
{
    if (!m_pm)
        throw exception::InternalError( "Tried to commit without PM" );

    // mornfall: is it me or this looks like a race?
    while (1) {
        _system->UnLock(); // unlock for dpkg to take over
        pkgPackageManager::OrderResult Res = m_pm->DoInstall(-1);
        if (Res == pkgPackageManager::Completed) {
            _system->Lock(); // regain lock
            delete m_pm;
            m_pm = 0;
            cache::Global::get( m_cache ).reopen(); // reopen cache
            return;
        } else if (Res == pkgPackageManager::Failed) {
            throw exception::Error( "Error installing packages" );
        }
        exception::checkGlobal( "Error installing packages" );
        getArchives();
    }
}

// mornfall: this needs to be unfucked (exceptions, make it safe, etc)
void Manager::update()
{
    cache::Cache &c = cache::Global::get( m_cache );

    try {
        pkgSourceList SList;
        if(!SList.ReadMainList())
            throw exception::Error( "The list of sources could not be read.");
        
        FileFd Lock;
        Lock.Fd(GetLock(_config->FindDir("Dir::State::Lists") + "lock"));
        exception::checkGlobal( "Unable to lock the list directory" );
        
        createFetcher();
        SList.GetIndexes( m_fetcher );

        fetch();
        
        bool Failed = false;
        string FailedURI;
        for (pkgAcquire::ItemIterator I = m_fetcher->ItemsBegin();
             I != m_fetcher->ItemsEnd(); I++)
        {
            if ((*I)->Status == pkgAcquire::Item::StatDone)
                continue;
            
            (*I)->Finished();
            
            if((*I)->ErrorText.empty())
                FailedURI += (*I)->DescURI() + "\n";
            else
                FailedURI += (*I)->DescURI() + ": " + (*I)->ErrorText + "\n";
            Failed = true;
        }
        
        // Clean out any old list files
        if (_config->FindB("APT::Get::List-Cleanup",true) == true)
        {
            if ( m_fetcher->Clean(_config->FindDir("Dir::State::lists")) == false ||
                 m_fetcher->Clean(_config->FindDir("Dir::State::lists")
                                  + "partial/") == false )
                ; //return false;
        }
        
        // Reread the cache
        c.reopen();
    } catch (...) {
        c.reopen();
        throw;
    }

    }
    
#ifdef COMPILE_TESTSUITE
#include "test-utils.h"
#include "init.h"

namespace tut {

struct manager_shar {
    manager_shar () {
	  aptInit ();
    }
};


TESTGRP( manager );

template<> template<>
void to::test<1> ()
{
    cache::Cache &cache = cache::Global::get();
}

}

#endif
