#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {
	class SuperHero :public Hero {
	protected:
		int super_Attbonus;
		int super_Def;
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		~SuperHero();
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero&, const SuperHero&);
}
#endif // !SICT_SUPERHERO_H



