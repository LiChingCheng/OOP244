// Final Project Milestone 2 - Error Class
// Version 3.4
// Error.cpp
// Date	2018-10-18
// Author	Chris Szalwinski, Fardad Soleimanloo
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
// --------------------------------------------------------------
// Name  Li - Ching, Cheng  Date  2018 / 10 / 31
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;

namespace aid {
	Error::Error(const char* errorMessage) {
		if (errorMessage == nullptr || errorMessage[0] == '\0') {
			add_Message = nullptr;
		}
		else {
			int count;
			count = strlen(errorMessage);
			add_Message = nullptr;
			add_Message = new char[count + 1];
			strcpy(add_Message, errorMessage);
		}
	}

	Error::~Error() {
		delete[] add_Message;
		add_Message = nullptr;
	}

	void Error::clear() {
		add_Message = nullptr;
	}

	bool Error::isClear() const {
		bool clear = false;
		if (add_Message == nullptr) {
			clear = true;
		}
		return clear;
	}

	void Error::message(const char* str) {
		int count;
		delete[] add_Message;
		add_Message = nullptr;
		if (str == nullptr || str[0] == '\0') {
			add_Message = nullptr;
		}
		else {
			count = strlen(str);
			add_Message = new char[count + 1];
			strcpy(add_Message, str);
		}
	}

	const char* Error::message() const {
		const char* temp;
		if (add_Message != nullptr) {
			temp = add_Message;
		}
		else {
			temp = nullptr;
		}
		return temp;
	}

	ostream& operator<<(ostream& os, const Error& em) {
		if (!em.isClear()) {
			cout << em.message();
		}
		return os;
	}
}


