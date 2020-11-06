#pragma once
/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 2018/09/17
// Author Cheng, Li-Ching
// Student number 143292175
// Email lcheng49@myseneca.ca
// Section SAB

***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace
namespace sict {

	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom&);

	void display(const struct Kingdom*, int);
}
#endif // !SICT_KINGDOM_H