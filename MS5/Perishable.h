// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
/////////////////////////////

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H
#include <iostream>
#include "Good.h"
#include "Date.h"
using namespace std;

namespace aid {
	class Perishable :public Good {
		Date expiryDate;
	public:
		Perishable();
		fstream& store(fstream& file, bool newline = true)const;
		fstream& load(fstream& file);
		ostream& write(ostream& os, bool linear)const;
		istream& read(istream& is);
		const Date& expiry() const;
	};
}
#endif // !AID_PERISHABLE_H



