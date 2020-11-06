// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
//////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

namespace sict {
	SavingsAccount::SavingsAccount(double balance, double rate) :Account(balance) {
		if (rate > 0) {
			interest_Rate = rate;
		}
		else {
			interest_Rate = 0.0;
		}
	}

	void SavingsAccount::monthEnd() {
		credit(balance()*interest_Rate);
	}

	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << std::endl;
		os << "Balance: $" << std::fixed; os << std::setprecision(2) << balance() << std::endl;
		os << "Interest Rate (%): " << interest_Rate * 100 << std::endl;
	}
}

