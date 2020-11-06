// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
////////////////////////////////////////////////////

#include <iostream>
#include "Data.h"
using namespace std;

namespace sict {

	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {
		double pop_Change;
		pop_Change = static_cast<double>(population[n - 1] - population[0]) / 1000000;
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout.precision(2); cout.setf(ios::fixed);
		cout << pop_Change << " million" << endl;

		const char* trend;		
		trend = violentCrime[0] > violentCrime[n - 1] ? "down" : "up";
		cout << "Violent Crime trend is " << trend << endl;

		double gta;
		gta = average(grandTheftAuto, n) / 1000000;
		cout << "There are ";
		cout.precision(2); cout.setf(ios::fixed);
		cout << gta << " million Grand Theft Auto incidents on average a year" << endl;

		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;
	}
	
}
