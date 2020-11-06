/***********************************************************

// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
//Name: Cheng, Li-Ching
//Student number: 143292175
//Email: lcheng49@myseneca.ca
//Section: SAB

***********************************************************/

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

namespace sict {

	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	void display(const Kingdom&);
}
#endif 