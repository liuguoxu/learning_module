#include <iostream>

using namespace std;

class Clock{
	public:
		void show();
		Clock();
	private:
		int hour;
		int min;
		int sec;
};

void Clock::show()
{
	cout<< "hour : "<< hour<<endl;
	cout<<"min : "<<min << endl;
	cout<< "sec : "<< sec << endl;
}

/*在构造函数中使用初始化列表*/
Clock::Clock(): hour(12), min(12), sec(12)
{
	cout << "new clock!" << endl;
}

int main()
{
	Clock a_clock;
	a_clock.show();
}
