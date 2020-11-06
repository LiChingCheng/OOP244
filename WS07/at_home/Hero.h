#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {

	const int MAX_ROUND = 100;
	const int MAX_NAME = 40;

	class Hero {
	public:	
		
		char hero_Name[MAX_NAME + 1];
		int hero_Health;
		int hero_Attack;

	public:
		Hero();
		Hero(const char*, int, int);
		~Hero();
		void operator-=(int);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<< (std::ostream&, const Hero&);
	};
	const Hero& operator*(const Hero&, const Hero&);
}
#endif // !SICT_HERO_H

