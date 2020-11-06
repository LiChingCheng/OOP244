// TODO: add file header comments here
/*
Workshop 4 - Constructors - Test Main
// Passenger.cpp
// Chris Szalwinski
// 2018/09/29
//Name: Li-Ching,Cheng
//ID  : 143292175
*/

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;
using namespace sict;

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() { 
		passenger_name [0]= '\0';
		destination[0] = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *passenName, const char *destinaName) {
		bool valid = passenName != nullptr&&destinaName != nullptr&&strlen(passenName) != 0 && strlen(destinaName) != 0;
		if (valid) {
			strncpy(passenger_name, passenName,(max-1));
			strncpy(destination, destinaName,(max-1));
			passenger_name[max-1] = '\0';
			destination[max-1] = '\0';
		}
		else {
			passenger_name[0] = '\0';
			destination[0] = '\0';
		}
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {

		if (strlen(passenger_name) == 0 && strlen(destination)==0 ){
			return true;
		}
		else {
			return false;
		}
	}

	// TODO: implement display query here
	void Passenger::display() const {

		if (!isEmpty()) {
			cout << passenger_name << " - " << destination << endl;
		}
		else
			cout << "No passenger!" << endl;

	}
}