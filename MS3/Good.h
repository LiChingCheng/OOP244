// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
/////////////////////////////

#ifndef AID_GOOD_H
#define AID_GOOD_H
#include <iostream>
#include "Error.h"
using namespace std;

namespace aid {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double TAX_RATE = 0.13;
	class Good {
		char good_Type;
		char good_Sku[max_sku_length + 1];
		char good_Uni[max_unit_length + 1];
		char * good_Name;
		int good_On_Hand;
		int good_Uni_Need;
		double good_Uni_Price;
		bool good_Taxable;
		Error error_State;
	protected:
		void name(const char* name);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Good(const char type = 'N');
		Good(const char* sku, const char* name, const char* unit, int qty = 0, bool tax = true, double price = 0, int needqty = 0);
		Good(const Good& good);
		Good& operator=(const Good& good);
		~Good();
		fstream& store(fstream& file, bool newline = true) const;
		fstream& load(fstream& file);
		ostream& write(ostream& os, bool linear) const;
		istream& read(istream& is);
		bool operator==(const char* sku) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* goodsku) const;
		bool operator>(const Good& good) const;
		int operator+=(int add);
	};
	ostream& operator<<(ostream& os, const Good& good);
	istream& operator>>(istream& is, Good& good);
	double operator+=(double& num, const Good& good);
}
#endif // !AID_GOOD_H


