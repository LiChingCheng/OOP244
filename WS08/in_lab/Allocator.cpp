// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
//////////////////////////////////////////////////////
#include "SavingsAccount.h" 

namespace sict {
	const double interest_Rate = 0.05;
	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* temp = nullptr;
		if (type[0] == 'S') {
			temp = new SavingsAccount(balance, interest_Rate);
		}
		else {
			temp = nullptr;
		}
		return temp;
	}
}