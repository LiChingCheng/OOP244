/***********************************************************

// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 2018/09/17
// Author Cheng, Li-Ching
// Student number 143292175
// Email lcheng49@myseneca.ca
// Section SAB

***********************************************************/

#include <iostream>
#include "Kingdom.h"
using namespace std;

namespace sict {

	//This function receive a Kingdom struct parameter and print them out
	void display(const Kingdom& kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}

	//dispaly function receive a kingdom struct parameter and the size of dynamic memory
	void display(const struct Kingdom* kingdom, int count) {

		int total_population = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < count; i++) {
			cout << i + 1 << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
			total_population += kingdom[i].m_population;
		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total_population << endl;
		cout << "------------------------------" << endl;
	}
}