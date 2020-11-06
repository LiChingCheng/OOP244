/*
Name:    Li-Ching, Cheng
ID:      143292175
Program: CPD
section: B
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include "Fraction.h"
using namespace std;
using namespace sict;

namespace sict {
	
	Fraction::Fraction() {
		numera = 0;
		denomina = 0;
	}
	
	Fraction::Fraction(int numerator, int denominator) {
		if (numerator >= 0 && denominator > 0) {
			numera = numerator;
			denomina = denominator;
			reduce();
		}
		else {
			numera = 0;
			denomina = 0;
		}
	}

	Fraction::~Fraction() {
	}
	
	int Fraction::max() const {

		return std::max(numera, denomina);
	}
	
	int Fraction::min() const {

		return std::min(numera, denomina);
	}
	
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}
	
	void Fraction::reduce() {

		int greatestDiv = gcd();

		numera /= greatestDiv;
		denomina /= greatestDiv;	
	}
	
	void Fraction::display() const {

		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if (!isEmpty()) {
			if (denomina == 1) {
				cout << numera;
			}
			else
			{
				cout << numera << "/" << denomina;
			}
		}
	}

	bool Fraction::isEmpty() const {
		if (numera == 0 && denomina == 0)
			return true;
		else
			return false;
	}
	
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction a;
		if (!rhs.isEmpty() && !isEmpty() ) {
			a.numera = ((rhs.numera*denomina) + (numera*rhs.denomina));
			a.denomina = (rhs.denomina*denomina);
			return a;
		}
		else
		{
			return a;
		}
	}
}


