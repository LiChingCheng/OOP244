#include <iostream>
#include <cstring>
#include "SuperHero.h"

namespace sict {
	SuperHero::SuperHero() {
		super_Attbonus = 0;
		super_Def = 0;
	}

	SuperHero::SuperHero(const char* name, int health, int attack, int attbonus, int defend) :Hero(name, health, attack) {
		super_Attbonus = attbonus;
		super_Def = defend;
	}

	SuperHero::~SuperHero() {
	}

	int SuperHero::attackStrength() const {
		return Hero::attackStrength() > 0 ? (Hero::attackStrength() + super_Attbonus) : 0;
	}

	int SuperHero::defend() const {
		return super_Def > 0 ? super_Def : 0;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero left = first;
		SuperHero right = second;
		const SuperHero* temp;
		int round = 0;
		for (int i = 0; i < MAX_ROUND; ++i) {
			if (left.attackStrength() != 0 && right.attackStrength() != 0 && left.isAlive() && right.isAlive()) {
				left -= (right.attackStrength()-left.defend());
				right -= (left.attackStrength()-right.defend());
				round = i + 1;
			}
		}
			std::cout << "Super Fight! " << first << " vs " << second << " : ";
		if (left.isAlive()) {
			std::cout << "Winner is " << first << " in " << round << " rounds." << std::endl;
			temp = &first;
		}
		else if (right.isAlive()) {
			std::cout << "Winner is " << second << " in " << round << " rounds." << std::endl;
			temp = &second;
		}
		return *temp;
	}
}







