/*
Workshop 4 - Constructors - Test Main
// Passenger.h
// Chris Szalwinski
// 2018/09/29
//Name: Li-Ching,Cheng
//ID  : 143292175
*/

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define max 19

namespace sict {
	
	class Passenger {

		char passenger_name[max];
		char destination[max];
		int depart_year;
		int depart_month;
		int depart_day;

	public:
		Passenger();
		Passenger(const char *, const char *);
		Passenger(const char *, const char *,int,int,int);
		
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;
		~Passenger();
	};
}

#endif // !SICT_PASSENGER_H