// Name: Li-Ching, Cheng
// ID: 143292175
// Section: B
////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

namespace sict {

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	template <typename T>
	T max(const T* record, int n) {
		T temp = record[0];
		for (int i = 0; i < n; i++) {
			if (temp < record[i]) {
				temp = record[i];
			}
		}
		return temp;
	}

	template <typename T>
	T min(const T* record, int n) {
		T temp = record[0];
		for (int i = 0; i < n; i++) {
			if (temp > record[i]) {
				temp = record[i];
			}
		}
		return temp;
	}

	template <typename T>
	T sum(const T* record, int n) {
		T temp = 0;
		for (int i = 0; i < n; i++) {
			temp += record[i];
		}
		return temp;
	}

	template <typename T>
	double average(const T* record, int n) {
		return sum(record, n) / n;
	}

	template <typename T>
	bool read(std::istream& input, T* record, int n) {
		bool data = true;
		for (int i = 0; i < n; i++) {
			input.ignore();
			input >> record[i];
			if (input.fail()) {
				data = false;
			}
		}
		return data;
	}

	template <typename T>
	void display(const char* item, T* record, int n) {
		cout.width(20);
		cout << right << item;
		for (int i = 0; i < n; i++) {
			cout.width(15);
			cout << record[i];
		}
		cout << endl;
	}

	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();
		if (ok) {
			input.get(rowname, 2000, ',');
			if (std::strcmp(rowname, name) != 0) {
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}
		if (ok)
			ok = read(input, data, n);

		input.ignore(2000, '\n');
		return ok;
	}
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}
