/** -*- C++ -*-
 * @file cache/entity/desktop.h
 * @author Peter Rockai <me@mornfall.net>
 */

#include <iostream>
#include <string>
#include <map>

#ifndef APTFRONT_UTILS_DESKTOPFILE_H
#define APTFRONT_UTILS_DESKTOPFILE_H

namespace aptFront {
namespace utils {

struct DesktopFile {
    struct Entry {
        std::string key;
        std::string value;
    };
    typedef std::map< std::string, Entry > EntryMap;

    struct Group {
        std::string name;
        EntryMap entries;
        Entry &entry( std::string k ) { return entries[ k ]; }
    };

    typedef std::map< std::string, Group > GroupMap;
    GroupMap groups;
    Group &group( std::string k ) { return groups[ k ]; }
};

inline std::istream &operator >>( std::istream &i, DesktopFile::Entry &e )
{
    std::string spaces = ""; char c; bool started = false;

    e.key = "";
    // read key
    while ( i.peek() != EOF ) {
        c = i.get();
        if ( !started && c == '\n' )
            return i >> e;
        if ( isspace( c ) ) {
            spaces += c;
            continue;
        }
        if ( !started && c == '#' ) {
            while( i.peek() != EOF && i.get() != '\n' ); // read till eol
            return i >> e; // restart reading
        }
        started = true;
        if ( c == '=' )
            break;
        e.key += spaces;
        e.key += c;
        spaces = "";
    }
    // std::cerr << "read key: " << e.key << std::endl;

    started = false;
    bool backslash = false;
    // read value
    while ( i.peek() != EOF ) {
        c = i.get();
        if ( c == '\n' ) {
            if ( backslash )
                e.value += '\\';
            return i;
        }
        if ( !started && isspace( c ) )
            continue;
        started = true;
        if ( backslash ) { // interpret escape sequences
            if ( c == '\\' ) e.value += '\\';
            else if ( c == 'n' ) e.value += '\n';
            else if ( c == 't' ) e.value += '\t';
            else if ( c == 'r' ) e.value += '\r';
            else if ( c == 's' ) e.value += ' ';
            else { e.value += '\\'; e.value += c; }
            backslash = false;
            continue;
        }
        if ( c == '\\' ) {
            backslash = true;
            continue;
        }
        e.value += c;
    }
    return i;
}

inline std::istream &operator >>( std::istream &i, DesktopFile::Group &g )
{
    bool started = false; char c;
    g.name = "";
    while ( i.peek() != EOF ) {
        c = i.get();
        if ( !started && isspace( c ) )
            continue;
        if ( !started && c == '#' ) {
            while( i.peek() != EOF && i.get() != '\n' ); // read till eol
            return i >> g; // restart reading
        }
        if ( !started && c == '[' ) {
            started = true;
            continue;
        }
        if ( started && c == ']' ) {
            while( i.peek() != EOF && i.get() != '\n' ); // read till eol
            break;
        }
        g.name += c;
    }
    while ( i.peek() != EOF ) {
        DesktopFile::Entry e;
        i >> e;
        g.entries[ e.key ] = e;
    }
    return i;
}

inline std::istream &operator >>( std::istream &i, DesktopFile &f )
{
    while ( i.peek() != EOF ) {
        DesktopFile::Group g;
        i >> g;
        f.groups[ g.name ] = g;
    }
    return i;
}

}
}

#endif
