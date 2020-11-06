// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
/////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Good.h"
using namespace std;

namespace aid {

	void Good::name(const char* gname) {		
		if (gname != nullptr) {
			if (good_Name != nullptr) {
				delete[] good_Name;
				good_Name = nullptr;
				good_Name = new char[strlen(gname) + 1];
				strcpy(good_Name, gname);
			}
			else {
				good_Name = new char[strlen(gname) + 1];
				strcpy(good_Name, gname);
			}
		}
		else {
			if (good_Name != nullptr) {
				delete[] good_Name;
				good_Name = nullptr;
			}
			else {
				good_Name = nullptr;
			}
		}
	}
	
	const char* Good::name() const {
		return good_Name;  
	}

	const char* Good::sku() const {
		return good_Sku;
	}

	const char* Good::unit() const {
		return good_Uni;
	}

	bool Good::taxed() const {
		return good_Taxable;
	}

	double Good::itemPrice() const {
		return good_Uni_Price;
	}

	double Good::itemCost() const {
		return taxed() ? (itemPrice()*(1 + TAX_RATE)) : itemPrice();
	}

	void Good::message(const char* message) {
		error_State.message(message);
	}
	bool Good::isClear() const {
		return error_State.isClear();
	}

	Good::Good(const char type) {
		good_Type = type;
		good_Sku[0] ='\0';
		good_Uni[0]='\0';
		good_Name = nullptr;
		good_On_Hand = 0;
		good_Uni_Need = 0;
		good_Uni_Price = 0;
		good_Taxable = true;  
	}

	Good::Good(const char* sku, const char* goodname, const char* unit, int qty, bool tax, double price, int needqty) {
		strncpy(good_Sku, sku, max_sku_length);
		good_Sku[max_sku_length] = '\0';  
		good_Name = nullptr;
		name(goodname);
		strncpy(good_Uni, unit, max_unit_length);
		good_Uni[max_unit_length] = '\0'; 
		good_On_Hand = qty;
		good_Taxable = tax;
		good_Uni_Price = price;
		good_Uni_Need = needqty;
	}

	Good::Good(const Good& good) {
		good_Name = nullptr;
		*this = good;
	}

	Good& Good::operator=(const Good& good) {
		if (this != &good) {
			if (good.good_Type == 'P'||good.good_Type=='N') {
				good_Type = good.good_Type;
			}
			strcpy(good_Sku, good.good_Sku);
			strcpy(good_Uni, good.good_Uni);
			name(good.good_Name);
			good_On_Hand = good.good_On_Hand;
			good_Uni_Need = good.good_Uni_Need;
			good_Uni_Price = good.good_Uni_Price;
			good_Taxable = good.good_Taxable;
			message(good.error_State.message());  
		}
		return *this;
	}

	Good::~Good() {
		delete[] good_Name;
		good_Name = nullptr;
	}

	fstream& Good::store(fstream& file, bool newline) const {
		file << good_Type << "," << sku() << "," << name() << "," << unit() << ","
			<< taxed() << "," << itemPrice() << "," << quantity() << "," << qtyNeeded();
		if (newline == true) {
			file << endl;
		}
		return file;
	}

	fstream& Good::load(fstream& file) {
		char goodSku[max_sku_length + 1];
		char goodName[max_name_length + 1];
		char goodUni[max_unit_length + 1];
		bool goodTaxable;
		double goodUniPrice;
		int goodOnHand;
		int goodUniNeed;
		if (file.is_open()) {
			file.getline(goodSku, max_sku_length + 1, ',');
			file.getline(goodName, max_name_length + 1, ',');
			file.getline(goodUni, max_unit_length + 1, ',');
			file >> goodTaxable;
			file.ignore();
			file >> goodUniPrice;
			file.ignore();
			file >> goodOnHand;
			file.ignore();
			file >> goodUniNeed;
			file.ignore();
			Good temp(goodSku, goodName, goodUni, goodOnHand, goodTaxable, goodUniPrice, goodUniNeed);
			*this = temp;
		}
		return file;
	}

	ostream& Good::write(ostream& os, bool linear) const {
			if (!isClear()) {
				os << error_State.message();
			}
			else if(linear){
				os.setf(std::ios::fixed);
				os << setw(max_sku_length) << left << good_Sku << "|"
					<< setw(20) << left << name() << "|"
					<< setw(7) << setprecision(2) << right << itemCost() << "|"
					<< setw(4) << right << quantity() << "|"
					<< setw(max_unit_length) << left << unit() << "|"
					<< setw(4) << right << qtyNeeded() << "|";
			}
			else {
				os << " Sku: " << sku() << endl;
				os << " Name (no spaces): ";
				int count = strlen(good_Name) > max_name_length ? max_name_length : strlen(good_Name);
				for (int i = 0; i < count; i++) {
					os << good_Name[i];
				}
				os << endl;
				os << setw(7) << " Price: " << itemPrice() << endl;
				os << " Price after tax: ";
				if (good_Taxable) {
					os << itemCost() << endl;
				}
				else {
					os << " N/A" << endl;
				}
				os << " Quantity on Hand: " << quantity() << " " << unit() << endl;
				os << " Quantity needed: " << qtyNeeded();
			}
		return os;
	}

	istream& Good::read(istream& is) {
		char sku[max_sku_length + 1];
		char uni[max_unit_length + 1];
		char *name = new char[max_name_length + 1];
		int on_Hand;
		int uni_Need;
		double uni_Price;
		char tax;
		bool taxable;
		Error State;
		cout << " Sku: "; is >> sku;
		cout << " Name (no spaces): "; is >> name;
		cout << " Unit: "; is >> uni;
		cout << " Taxed? (y/n): "; is >> tax;
		if (tax == 'Y' || tax == 'y')
		{
			taxable = true;
		}
		else if (tax == 'N' || tax == 'n')
		{
			taxable = false;
		}
		else 
		{
			is.setstate(std::ios::failbit);
			message("Only (Y)es or (N)o are acceptable");
		}
		if (!is.fail()) {
			cout << " Price: "; is >> uni_Price;
			if (is.fail()) {
				message("Invalid Price Entry");
			}
		}
		if (!is.fail()) {
			cout << " Quantity on hand: "; is >> on_Hand;
			if (is.fail()) {
				message("Invalid Quantity Entry");
			}
		}
		if (!is.fail()) {
			cout << " Quantity needed: "; is >> uni_Need;
			if (is.fail()) {
				message("Invalid Quantity Needed Entry");
			}
		}
		if (!is.fail()) {		
			*this = Good(sku, name, uni, on_Hand, taxable, uni_Price, uni_Need);
		}	
		cin.ignore(1000, '\n');
		return is;
	}

	bool Good::operator==(const char* sku) const {
		return strcmp(sku, good_Sku) == 0 ? true : false;
	}
	
	double Good::total_cost() const {
		return good_On_Hand*itemCost();
	}

	void Good::quantity(int onHand) {
		if (onHand >= 0) {
			good_On_Hand = onHand;
		}
	}

	bool Good::isEmpty() const {
		return good_Name == nullptr ? true : false;
	}

	int Good::qtyNeeded() const {
		return good_Uni_Need;
	}

	int Good::quantity() const {
		return good_On_Hand;
	}

	bool Good::operator>(const char* goodsku) const {
		return strcmp(good_Sku, goodsku) > 0 ? true : false;
	}

	bool Good::operator>(const iGood& good) const {
		return strcmp(good_Name, good.name()) > 0 ? true : false;
	}

	int Good::operator+=(int add) {
		if (add > 0) {
			good_On_Hand += add;
		}
		return good_On_Hand;
	}

	ostream& operator<<(ostream& os, const iGood& good) {
		good.write(os, true);
		return os;
	}

	istream& operator>>(istream& is, iGood& good) {
		good.read(is);
		return is;
	}

	double operator+=(double& num, const iGood& good) {
		return good.total_cost() + num;
	}
}
