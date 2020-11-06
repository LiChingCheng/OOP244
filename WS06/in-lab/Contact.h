// Name:Li-Ching,Cheng
// ID:  143292175
// Section: B

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {

	const int MAX_CHAR = 20;

	class Contact {	

		public:
		char name[MAX_CHAR+1];
		long long* number;
		int num_of_phone;

	public:
		Contact();
		Contact(const char*, long long*, int);
		Contact(const Contact&);
		~Contact();
		Contact& operator=(const Contact&);
		Contact& operator+=(long long);
		bool isEmpty() const;
		void display() const;
	};
}
#endif // !SICT_CONTACT_H