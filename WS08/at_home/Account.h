// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
//////////////////////////////////////////////////////
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include "iAccount.h"

namespace sict {
	class Account :public iAccount {
		double account_Balance;
	protected:
		double balance() const;
	public:
		Account(double);
		bool credit(double);
		bool debit(double);
	};
}
#endif
