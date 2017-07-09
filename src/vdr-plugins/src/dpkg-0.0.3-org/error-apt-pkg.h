#ifndef PKGLIB_ERROR_H
#define PKGLIB_ERROR_H

#include "macros-apt-pkg.h"

#include <iostream>
#include <list>
#include <string>

#include <stddef.h>
#include <stdarg.h>

class GlobalError
{
public:		
	enum MsgType {
		FATAL = 40,
		ERROR = 30,
		WARNING = 20,
		NOTICE = 10,
//		DEBUG = 0
	};
/*	bool FatalE(const char *Function,const char *Description,...) APT_PRINTF(3) APT_COLD;
	bool Errno(const char *Function,const char *Description,...) APT_PRINTF(3) APT_COLD;
	bool WarningE(const char *Function,const char *Description,...) APT_PRINTF(3) APT_COLD;
	bool NoticeE(const char *Function,const char *Description,...) APT_PRINTF(3) APT_COLD;
	bool DebugE(const char *Function,const char *Description,...) APT_PRINTF(3) APT_COLD;
	bool InsertErrno(MsgType const &type, const char* Function,
			 const char* Description,...) APT_PRINTF(4) APT_COLD;
	bool InsertErrno(MsgType type, const char* Function,
			 const char* Description, va_list &args,
			 int const errsv, size_t &msgSize) APT_COLD;
	bool Fatal(const char *Description,...) APT_PRINTF(2) APT_COLD;
	bool Error(const char *Description,...) APT_PRINTF(2) APT_COLD;
	bool Warning(const char *Description,...) APT_PRINTF(2) APT_COLD;
	bool Notice(const char *Description,...) APT_PRINTF(2) APT_COLD;
	bool Debug(const char *Description,...) APT_PRINTF(2) APT_COLD;
	bool Insert(MsgType const &type, const char* Description,...) APT_PRINTF(3) APT_COLD;
	bool Insert(MsgType type, const char* Description,
			 va_list &args, size_t &msgSize) APT_COLD;  */
	inline bool PendingError() const APT_PURE {return PendingFlag;};
	bool empty(MsgType const &threshold = WARNING) const APT_PURE;
	bool PopMessage(std::string &Text);
	void Discard();
	void DumpErrors(std::ostream &out, MsgType const &threshold = WARNING,
			bool const &mergeStack = true);
	void inline DumpErrors(MsgType const &threshold) {
		DumpErrors(std::cerr, threshold);
	}
	void inline DumpErrors() {
                DumpErrors(WARNING);
	}
	void PushToStack();
	void RevertToStack();
	void MergeWithStack();
	size_t StackCount() const APT_PURE {
		return Stacks.size();
	}

	GlobalError();
	
private:
	struct Item {
		std::string Text;
		MsgType Type;

		Item(char const *Text, MsgType const &Type) :
			Text(Text), Type(Type) {};

		friend std::ostream& operator<< (std::ostream &out, Item i) {
			switch(i.Type) {
			case FATAL:
			case ERROR: out << "E"; break;
			case WARNING: out << "W"; break;
			case NOTICE: out << "N"; break;
//			case DEBUG: out << "D"; break;
			}
			return out << ": " << i.Text;
		}
	};

	std::list<Item> Messages;
	bool PendingFlag;

	struct MsgStack {
		std::list<Item> const Messages;
		bool const PendingFlag;

		MsgStack(std::list<Item> const &Messages, bool const &Pending) :
			 Messages(Messages), PendingFlag(Pending) {};
	};

	std::list<MsgStack> Stacks;

};
GlobalError *_GetErrorObj();
#define _error _GetErrorObj()

#endif
