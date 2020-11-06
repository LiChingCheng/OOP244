// Name:Li-Ching,Cheng
// ID:  143292175
// Section: B
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

namespace sict {

	Hero::Hero() {
		hero_Name[0] = '\0';
		hero_Health = 0;
		hero_Attack = 0;
	}

	Hero::Hero(const char* name, int health, int attack) {
		bool valid = name != nullptr&&name[0] != '\0'&&health > 0 && attack > 0;
		if (valid) {
			strncpy(hero_Name,name,MAX_NAME);
			hero_Name[MAX_NAME] = '\0';
			hero_Health = health;
			hero_Attack = attack;
		}
		else {
			*this = Hero();
		}
	}

	Hero::~Hero() {
	}

	void Hero::operator-=(int attack) {
		if (attack > 0 && hero_Health > 0) {
			hero_Health -= attack;
			if (hero_Health < 0) {
				hero_Health = 0;
			}
		}
	}

	bool Hero::isAlive() const {
		return (hero_Health > 0) ? true : false;
	}

	int Hero::attackStrength() const {
		int attack = 0;
		if (hero_Attack > 0) {
			attack = hero_Attack;
		}
		return attack;
	}

	const char* Hero::getName() const{
		return hero_Name;
	}

	std::ostream& operator<< (std::ostream& os, const Hero& hero) {
		if (hero.hero_Name[0] == '\0'&&hero.hero_Health == 0 && hero.hero_Attack == 0) {
			os << hero.hero_Name;
		}
		else {
			os << "No hero";
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero left = first;
		Hero right = second;
		const Hero* temp;
		int round = 0;
		for (int i = 0; i < MAX_ROUND; i++) {
			if (left.attackStrength() != 0 && right.attackStrength() != 0 && left.isAlive() && right.isAlive()) {
				left -= right.attackStrength();
				right -= left.attackStrength();
				round = i + 1 ;
			}
		}
			std::cout << "Ancient Battle! " << first.getName() << " vs " << second.getName() << " : ";
		if (left.isAlive()) {
			std::cout << "Winner is " <<first.getName() << " in " << round << " rounds." << std::endl;
			temp = &first;
		}
		else if (right.isAlive()) {
			std::cout << "Winner is " << second.getName() << " in " << round << " rounds." << std::endl;
			temp = &second;
		}
		else if(!left.isAlive() && !right.isAlive()){
			std::cout << "Winner is " <<first.getName() << " in " << round << " rounds." << std::endl;
			temp = &first;
		}
		else if (left.isAlive() && right.isAlive() && round == 100) {
			std::cout << "Winner is " << first.getName() << " in " << round << " rounds." << std::endl;
			temp = &first;
		}
		return *temp;
	}
}

