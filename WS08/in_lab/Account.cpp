// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
//////////////////////////////////////////////////////
#include <iostream>
#include "Account.h"

namespace sict {
	double Account::balance() const {
		return account_Balance;
	}

	Account::Account(double balance) {
		if (balance > 0) {
			account_Balance = balance;
		}
		else {
			account_Balance = 0.0;
		}
	}

	bool Account::credit(double credit) {
		bool add = false;
		if (credit > 0) {
			account_Balance += credit;
			add = true;
		}
		return add;
	}

	bool Account::debit(double debit) {
		bool subtract = false;
		if (debit > 0) {
			account_Balance -= debit;
			subtract = true;
		}
		return subtract;
	}
}