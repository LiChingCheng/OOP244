// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
//////////////////////////////////////////////////////
#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__
#include <iostream>

namespace sict {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() {};
	};
	iAccount* CreateAccount(const char* type, double balance);
}
#endif

