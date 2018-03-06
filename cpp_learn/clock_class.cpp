#include <iostream>

using namespace std;

class clock{
	public:
		void show();
		void init();
	private:
		int hour;
		int min;
		int sec;
};

void clock::show()
{
	cout<< "hour : "<< hour<<endl;
	cout<<"min : "<<min << endl;
	cout<< "sec : "<< sec << endl;
}

void clock::init()
{
	hour = 12;
	min = 12;
	sec = 12;
}

int main()
{
	clock a_clock;
	a_clock.init();
	a_clock.show();
}
