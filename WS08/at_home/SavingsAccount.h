// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
//////////////////////////////////////////////////////
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include "Account.h"

namespace sict {
	class SavingsAccount :public Account {
		double interest_Rate;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif
