/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
// Version 2.1
// 2017/09/09
// Chris Szalwinski
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			      Date		              Reason
// Li-Ching,Cheng     2018/09/23
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;
using namespace sict;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		if (sin >= min_sin && sin <= max_sin) {
			strncpy(family_Name, familyName, max_name_length);
			strncpy(given_Name, givenName, max_name_length);
			family_Name[max_name_length] = '\0';
			given_Name[max_name_length] = '\0';
			sin_Num = sin;
		}
		else
			sin_Num = 0;
	}

	bool CRA_Account::isEmpty() const {
		return sin_Num == 0;
	}

	void CRA_Account::display() const {
		
		if (!isEmpty()){
		cout << "Family Name: " << family_Name << endl;
		cout << "Given Name : " << given_Name << endl;
		cout << "CRA Account: " << sin_Num << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

}