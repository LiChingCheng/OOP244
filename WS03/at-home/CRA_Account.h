/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
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

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;


	class CRA_Account {
		char family_Name[max_name_length + 1];
		char given_Name[max_name_length + 1];
		int sin_Num;
		int return_year[max_yrs];
		double balances[max_yrs];
		int num_of_year = 0;

	public:
		bool valid(const int sin);
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
	};
}

#endif // !SICT_CRA_ACCOUNT_H
