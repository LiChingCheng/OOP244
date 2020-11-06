/*
Workshop 4 - Constructors - Test Main
// Passenger.cpp
// Chris Szalwinski
// 2018/09/29
//Name: Li-Ching,Cheng
//ID  : 143292175
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Passenger.h"
using namespace std;
using namespace sict;

namespace sict {

	Passenger::Passenger() {
		*passenger_name = '\0';
		*destination = '\0';
		depart_year = 0;
		depart_month = 0;
		depart_day = 0;
	}

	Passenger::Passenger(const char *passenName, const char *destinaName) {

		bool valid = passenName != nullptr&&destinaName != nullptr&&strlen(passenName) != 0 && strlen(destinaName) != 0;
		if (valid) {
			strncpy(passenger_name, passenName, (max - 1));
			strncpy(destination, destinaName, (max - 1));
			passenger_name[max - 1] = '\0';
			destination[max - 1] = '\0';
			depart_year = 2018;
			depart_month = 10;
			depart_day = 1;
		}
		else {
			*passenger_name = '\0';
			*destination = '\0';
		}
	}

	Passenger::Passenger(const char *passenName, const char *destinaName, int year, int month, int day) {
		
		bool valid = (passenName != nullptr && destinaName != nullptr && strlen(passenName) != 0 && strlen(destinaName) != 0
			&& year >= 2018 && year <= 2020 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
		
		if (valid) {
			strncpy(passenger_name, passenName, (max - 1));
			strncpy(destination, destinaName, (max - 1));
			passenger_name[max - 1] = '\0';
			destination[max - 1] = '\0';
			depart_year = year;
			depart_month = month;
			depart_day = day;
		}
		else {
			*passenger_name = '\0';
			*destination = '\0';
		}
	}

	Passenger::~Passenger() {

	}
	
	const char* Passenger::name() const {

		return this->passenger_name;
	};

	bool Passenger::canTravelWith(const Passenger& passenger) const {

		bool valid = (strcmp(passenger.destination,this->destination)==0 && passenger.depart_year==this->depart_year
			&& passenger.depart_month==this->depart_month && passenger.depart_day==this->depart_day);
		
		if (valid)
			return true;
		else
			return false;
	}

	bool Passenger::isEmpty() const {

		if (strlen(passenger_name) == 0 && strlen(destination) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Passenger::display() const {

		if (!isEmpty()) {
			cout << this->passenger_name << " - " << this->destination << " on " << this->depart_year << "/" 
				<< setfill('0') << setw(2) << this->depart_month << "/" << setfill('0') << setw(2)
				<< this->depart_day << endl;
		}
		else
			cout << "No passenger!" << endl;
	}
}