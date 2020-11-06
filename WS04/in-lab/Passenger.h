// TODO: add file header comments here
/*
Workshop 4 - Constructors - Test Main
// Passenger.h
// Chris Szalwinski
// 2018/09/29
//Name: Li-Ching,Cheng
//ID  : 143292175
*/

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define max 19

// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {

		char passenger_name[max];
		char destination[max];

	public:
		Passenger();
		Passenger(const char *, const char *);

		bool isEmpty() const;
		void display() const;
	};
}

#endif // !SICT_PASSENGER_H