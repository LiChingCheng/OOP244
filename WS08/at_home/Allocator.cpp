// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
//////////////////////////////////////////////////////
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {
	const double interest_Rate = 0.05;
	const double tranaction_Fee = 0.50;
	const double month_End_Fee = 2.00;
	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* temp = nullptr;
		if (type[0] == 'S') {
			temp = new SavingsAccount(balance, interest_Rate);
		}
		else if (type[0] == 'C') {
			temp = new ChequingAccount(balance, tranaction_Fee, month_End_Fee);
		}
		else {
			temp = nullptr;
		}
		return temp;
	}
}
