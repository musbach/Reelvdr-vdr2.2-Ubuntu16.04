#ifndef DEBTAGS_REGEXP_H
#define DEBTAGS_REGEXP_H

/** \file
 * OO wrapper for regular expression functions
 */

/*
 * Copyright (C) 2003  Enrico Zini <enrico@debian.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 */

#include <tagcoll/Exception.h>
#include <sys/types.h>
#include <regex.h>

namespace Debtags
{

/**
 * Exception to report errors in parsing and matching regular expressions
 */
class RegexpException : public Tagcoll::SystemException
{
protected:
	std::string _message;

public:
	RegexpException(const regex_t& re, int code, const std::string& context)
		throw ();
	~RegexpException() throw () {}

	virtual const char* type() const throw () { return "RegexpException"; }
	virtual std::string desc() const throw () { return _message + " " + _context; }
};

/**
 * Encapsulate a regular expression
 */
class Regexp
{
protected:
	regex_t re;
	regmatch_t* pmatch;
	int nmatch;
	std::string lastMatch;

public:
	Regexp(const std::string& expr, int match_count = 0, int flags = 0) throw (RegexpException);
	~Regexp() throw ();

	bool match(const std::string& str, int flags = 0) throw (RegexpException);
	
	std::string operator[](int idx) throw (Tagcoll::OutOfRangeException);
};

/**
 * Encapsulate an extended regular expression
 */
class ExtendedRegexp : public Regexp
{
public:
	ExtendedRegexp(const std::string& expr, int match_count = 0, int flags = 0) throw (RegexpException)
		: Regexp(expr, match_count, flags | REG_EXTENDED) {}
};

};

// vim:set ts=4 sw=4:
#endif
