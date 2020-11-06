/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 3.0
// 2018/09/23
// Chris Szalwinski
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		          ID
// Li-Ching,Cheng     2018/09/23      143292175
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;
using namespace sict;

namespace sict {

	bool CRA_Account::valid(const int sin) {

		int SIN[9];
		int sinNum, digit, ten_digit;
		int oddSum = 0, evenSum = 0, total;

		if (sin >= min_sin && sin <= max_sin) {
			sinNum = sin;
			for (int i = 8; i >= 0; i--) {
				SIN[i] = (sinNum % 10);
				sinNum = sinNum / 10;
			}

			for (int i = 1; i < 8; i += 2) {
				ten_digit = SIN[i] * 2 / 10;
				digit = SIN[i] * 2 % 10;
				oddSum += (ten_digit + digit);
			}
			for (int i = 0; i < 8; i += 2) {
				evenSum += SIN[i];
			}
			total = (oddSum + evenSum);
			if ((SIN[8] + total) % 10 == 0) {
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		if (CRA_Account::valid(sin) && familyName[0] != '\0'&& givenName[0] != '\0') {
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

	void CRA_Account::set(int year, double balance) {

		if (!isEmpty() && num_of_year < max_yrs) {
			return_year[num_of_year] = year;
			balances[num_of_year] = balance;
			num_of_year ++;
		}
	}

	void CRA_Account::display() const {

		if (!isEmpty()) {

			cout << "Family Name: " << family_Name << endl;
			cout << "Given Name : " << given_Name << endl;
			cout << "CRA Account: " << sin_Num << endl;
			for (int i = 0; i < num_of_year; i++) {
				if (balances[i] > 2) {
					cout << "Year (" << return_year[i] << ") balance owing: " << balances[i] << endl;
				}
				else if (balances[i] < -2) {
					cout.setf(ios::fixed); cout.precision(1);
					cout << "Year (" << return_year[i] << ") refund due: " << -(balances[i]) <<  endl;
				}
				else {
					cout << "Year (" << return_year[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}
}