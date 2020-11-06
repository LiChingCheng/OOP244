/***********************************************************

// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
//Name: Cheng, Li-Ching
//Student number: 143292175
//Email: lcheng49@myseneca.ca
//Section: SAB

***********************************************************/

#include <iostream>
#include "Kingdom.h"
using namespace std;

namespace sict {

	//This function receive one Kingdom struct parameter and print them out
	void display(const Kingdom& kingdom) {

		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
}