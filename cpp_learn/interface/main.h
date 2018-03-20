#include <iostream>

using namespace std;

class Base {
	public:
		virtual void stand() = 0;
		virtual void eat() = 0;
};

class Jack: public Base {
	public:
		void stand() {
			cout << "Jack standing up!" << endl;	
		}
		void eat() {
			cout << "Jack eating!" <<endl;	
		}
};

class Peter: public Base {
	public:
		void stand() {
			cout << "Peter standing ip!" << endl;
		}
		void eat() {
			cout << "Peter eating !" << endl;	
		}
};
