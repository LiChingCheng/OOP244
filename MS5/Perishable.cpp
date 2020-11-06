// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
/////////////////////////////

#include <iostream>
#include <fstream>
#include "Perishable.h"
using namespace std;

namespace aid {

	Perishable::Perishable():Good('P') {
		isClear();
	}

	fstream& Perishable::store(fstream& file, bool newline)const {		
		Good::store(file, false);
		file << "," << expiryDate;
		if (newline) {
			file << endl;		
		}
		return file;
	}

	fstream& Perishable::load(fstream& file) {
		Good::load(file);		
		expiryDate.read(file);	
		file.ignore();
		return file;
	}

	ostream& Perishable::write(std::ostream& os, bool linear)const {
		Good::write(os, linear);
		if (!isEmpty() && isClear()) {
			if (linear) {
				expiryDate.write(os);
			}
			else {
				cout << endl;
				os << " Expiry date: ";
				expiryDate.write(os);
			}
		}
		return os;
	}

	istream& Perishable::read(std::istream& is) {
		//is.clear();
		Good::read(is);
		if (isClear()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			is >> expiryDate;
		}
		if (expiryDate.bad()) {
			is.setstate(std::ios::failbit);
			if (expiryDate.errCode() == CIN_FAILED) {
				message("Incalid Date Entry");
			}
			else if (expiryDate.errCode() == YEAR_ERROR) {
				message("Invalid Year in Date Entry");
			}
			else if (expiryDate.errCode() == MON_ERROR) {
				message("Invalid Month in Date Entry");
			}
			else if (expiryDate.errCode() == DAY_ERROR) {
				message("Invalid Day in Date Entry");
			}
			else if (expiryDate.errCode() == PAST_ERROR) {
				message("Invalid Expiry in Date Entry");
			}
		}
		return is;
	}

	const Date& Perishable::expiry() const {
		return expiryDate;
	}
}