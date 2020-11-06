/*
Name:    Li-Ching, Cheng
ID:      143292175
Program: CPD
section: B
*/

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
	
	class Fraction {
		
		int numera, denomina;
		
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		
		Fraction();
		Fraction(int, int);
		~Fraction();

		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction&) const;
		Fraction operator*(const Fraction&) const;
		bool operator==(const Fraction&) const;
		bool operator!=(const Fraction&) const;
		Fraction& operator+=(const Fraction&);
	};
}
#endif // !SICT_FRACTION_H



