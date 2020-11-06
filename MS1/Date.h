// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Li-Ching, Cheng  Date  2018/10/31
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

namespace aid {

	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int DAY_ERROR = 2;
	const int MON_ERROR = 3;
	const int YEAR_ERROR = 4;
	const int PAST_ERROR = 5;

	class Date {

		int years, months, days, err_state, comparator_v;
		bool valid(int, int, int);
		int mdays(int, int)const;;
		void errCode(int);

	public:
		Date();
		Date(int, int, int);
		~Date();
		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream&);
		std::ostream& write(std::ostream&) const;
		bool operator==(const Date&)const;
		bool operator!=(const Date&)const;
		bool operator<(const Date&)const;
		bool operator>(const Date&)const;
		bool operator<=(const Date&)const;
		bool operator>=(const Date&)const;
	};

	std::istream& operator>>(std::istream&, Date&);
	std::ostream& operator<<(std::ostream&, const Date&);
}
#endif