// Final Project Milestone 2 - Error Class
// Version 3.4
// Error.h
// Date	2018-10-18
// Author	Chris Szalwinski, Fardad Soleimanloo
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
// --------------------------------------------------------------
// Name  Li - Ching, Cheng  Date  2018 / 10 / 31
/////////////////////////////////////////////////////////////////

#ifndef AID_ERROR_H
#define AID_ERROR_H
#include <iostream>
using namespace std;

namespace aid {
	class Error {
		char* add_Message;
	public:
		explicit Error(const char* errorMessage = nullptr);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message() const;
	};
	ostream& operator<<(ostream&, const Error&);
}
#endif // !AID_ERROR_H

