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

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Date.h"
using namespace std;
using namespace aid;

namespace aid {

	bool Date::valid(int year, int month, int day) {
		bool state = false;
		if ((year >= min_year) && (year <= max_year) && (month >= 1)
			&& (month <= 12) && (day >= 1) && (day <= mdays(month, year))) {
			state = true;
		}
		return state;
	}

	// number of days in month mon and year year
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	Date::Date() {
		err_state = NO_ERROR;
		years = 0000;
		months = 00;
		days = 00;
		comparator_v = 0;
	}

	Date::Date(int year, int month, int day) {
		valid(year, month, day);
		if (valid(year, month, day)) {
			years = year;
			months = month;
			days = day;
			err_state = NO_ERROR;
			comparator_v = (year * 372 + month * 31 + day);
		}
		else {
			*this = Date();
		}
	}

	Date::~Date() {}

	void Date::errCode(int errCode) {
		err_state = errCode;
	}

	int Date::errCode() const {
		return err_state;
	}

	bool Date::bad() const {
		bool state = false;
		if (err_state != NO_ERROR) {
			state = true;
		}
		return state;
	}

	istream& Date::read(istream& istr) {

		int year, month, day;
		istr >> year;
		getchar();
		istr >> month;
		getchar();
		istr >> day;

		if (istr.fail()) {
			errCode(CIN_FAILED);
		}
		else if (year > max_year || year < min_year) {
			errCode(YEAR_ERROR);
		}
		else if (month > 12 || month < 1) {
			errCode(MON_ERROR);
		}
		else if (day < 1 || day > mdays(month, year)) {
			errCode(DAY_ERROR);
		}
		else if ((year * 372 + month * 31 + day) < min_date) {
			errCode(PAST_ERROR);
		}
		else {
			years = year;
			months = month;
			days = day;
		}
		return istr;
	}

	ostream& Date::write(ostream& ostr) const {
		ostr << setfill(' ');
		ostr << years << "/";
		ostr << setw(2) << setfill('0') << months << "/";
		ostr << setw(2) << setfill('0') << days;
		ostr << setfill(' ');
		return ostr;
	}

	bool Date::operator==(const Date& rhs)const {
		bool state = false;
		if ((years == rhs.years) && (months == rhs.months) && (days == rhs.days)) {
			state = true;
		}
		return state;
	}

	bool Date::operator!=(const Date& rhs) const {
		bool state = false;
		if ((years != rhs.years) || (months != rhs.months) || (days != rhs.days)) {
			state = true;
		}
		return state;
	}

	bool Date::operator<(const Date& rhs)const {
		bool state = false;
		if (comparator_v < rhs.comparator_v) {
			state = true;
		}
		return state;
	}

	bool Date::operator>(const Date& rhs)const {
		bool state = false;
		if (comparator_v > rhs.comparator_v) {
			state = true;
		}
		return state;
	}

	bool Date::operator<=(const Date& rhs)const {
		bool state = false;
		if (comparator_v <= rhs.comparator_v) {
			state = true;
		}
		return state;
	}

	bool Date::operator>=(const Date& rhs)const {
		bool state = false;
		if (comparator_v >= rhs.comparator_v) {
			state = true;
		}
		return state;
	}

	istream& operator>>(istream& istr, Date& rhs) {
		rhs.read(istr);
		return istr;
	}

	ostream& operator<<(ostream& ostr, const Date& rhs) {
		rhs.write(ostr);
		return ostr;
	}
};