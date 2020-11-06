// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
//////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"
using namespace std;

namespace sict {
	ChequingAccount::ChequingAccount(double balance, double transction, double month_end) :Account(balance) {
		transction > 0 ? (tranaction_Fee = transction) : (tranaction_Fee = 0.0);
		month_end > 0 ? (month_End_Fee = month_end) : (month_End_Fee = 0.0);
	}

	bool ChequingAccount::credit(double add) {
		bool charge = false;
		if (Account::credit(add)) {
			Account::debit(tranaction_Fee);
			charge = true;
		}
		return charge;
	}

	bool ChequingAccount::debit(double subtract) {
		bool charge = false;
		if (Account::debit(subtract)) {
			Account::debit(tranaction_Fee);
			charge = true;
		}
		return charge;
	}

	void ChequingAccount::monthEnd() {
		Account::debit(month_End_Fee);
	}
	
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << std::endl;
		os << "Balance: $" << std::fixed; os << std::setprecision(2) << balance() << endl;
		os << "Per Transaction Fee: " << tranaction_Fee << std::endl;
		os << "Monthly Fee: " << month_End_Fee << std::endl;
	}
}