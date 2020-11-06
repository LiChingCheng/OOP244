// Name:Li-Ching,Cheng
// ID:  143292175
// Section: B

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;

namespace sict {

	Contact::Contact() {
		name[0] = '\0';
		number = nullptr;
		num_of_phone = 0;
	}

	Contact::Contact(const char* cname, long long* pnumber, int num) {
		long long country_num, area_num, pnumbers;
		int count = 0;

		if (cname != nullptr&&cname[0] != '\0') {
			strncpy(name, cname, MAX_CHAR);
			name[MAX_CHAR] = '\0';

			for (int i = 0; i < num; i++) {
				country_num = pnumber[i] / 10000000000;
				area_num = pnumber[i] % 10000000000 / 10000000;
				pnumbers = pnumber[i] % 10000000;

				if (country_num > 0 && country_num < 100 && area_num >= 100 && area_num < 1000
					&& pnumbers >= 1000000 && pnumbers < 10000000) {
					count++;
				}
			}
			num_of_phone = count;
			number = new long long[count];
			int l = 0;

			for (int i = 0; i < num; i++) {
				country_num = pnumber[i] / 10000000000;
				area_num = pnumber[i] % 10000000000 / 10000000;
				pnumbers = pnumber[i] % 10000000;

				if (country_num > 0 && country_num < 100 && area_num >= 100 && area_num < 1000
					&& pnumbers >= 1000000 && pnumbers < 10000000) {
					number[l++] = pnumber[i];
				}
			}
		}
		else {
			name[0] = '\0';
			number = nullptr;
			num_of_phone = 0;
		}
	}

	Contact::Contact(const Contact& src) {	

		if (src.name != nullptr) {
			strcpy(name, src.name);
			num_of_phone = src.num_of_phone;
			if (src.number != nullptr) {
				number = new long long[num_of_phone];
				for (int i = 0; i < num_of_phone; i++) {
					number[i] = src.number[i];
				}
			}
			else {
				number = nullptr;
			}
		}
	}

	Contact::~Contact() {
		delete[] number;
		number = nullptr;
	}

	Contact& Contact::operator=(const Contact& src) {
		if (this != &src) {
			strcpy(name, src.name);
			num_of_phone = src.num_of_phone;
			delete[] number;
			if (src.number != nullptr) {
				number = new long long[num_of_phone];
				for (int i = 0; i < num_of_phone; i++) {
					number[i] = src.number[i];
				}
			}
			else {
				number = nullptr;
			}
		}
		return *this;
	}

	Contact& Contact::operator+=(long long newNum) {
		long long country_num, area_num, pnumbers;
		country_num = newNum / 10000000000;
		area_num = newNum % 10000000000 / 10000000;
		pnumbers = newNum % 10000000;

		if (country_num > 0 && country_num < 100 && area_num >= 100 && area_num < 1000
			&& pnumbers >= 1000000 && pnumbers < 10000000) {
			Contact temp=*this;
			delete[] number;
			num_of_phone++;
			number = new long long[num_of_phone];
			if (num_of_phone > 1) {
				for (int i = 0; i < num_of_phone; i++) {
					number[i] = temp.number[i];
				}
			}
			number[num_of_phone - 1] = newNum;
		}
		return *this;
	}

	bool Contact::isEmpty() const {
		bool state = false;
		if (name[0] == '\0') {
			state = true;
		}	
			return state;
	}

	void Contact::display() const {
		long long country_num, area_num, pnumbers3, pnumbers4;

		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;
			for (int i = 0; i < num_of_phone; i++) {
				country_num = number[i] / 10000000000;
				area_num = number[i] % 10000000000 / 10000000;
				pnumbers3 = number[i] % 10000000 / 10000;
				pnumbers4 = number[i] % 10000;
				cout << "(+" << country_num << ") " << area_num << " " << pnumbers3 << "-";
				cout.width(4); cout.fill('0'); cout << pnumbers4 << endl;
			}
		}
	}
}