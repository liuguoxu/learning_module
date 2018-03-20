#include <iostream>

using namespace std;


class Add {
	protected:
		virtual int add_func(int a, int b) {
			cout << "I am Add" << endl;
		}
};

class Mns {
	protected:
		virtual int mns_func(int a, int b) {
			cout << "I am Mns" << endl;
		}
};

class Calc: public Add ,public Mns{
	public:
		Calc(): x(12), y(10) {}
		Calc(int a, int b): x(a), y(b) {}
		int add_func(int a, int b);
		int mns_func(int a, int b);
	private:
		int x;
		int y;
};


int Calc:: add_func(int a, int b)
{
	return a+b;
}

int Calc:: mns_func(int a, int b)
{
	return a-b;
}

int main()
{
	Calc *tmp = new Calc;
	cout << tmp->add_func(100, 80)<< endl;
	cout << tmp-> mns_func(100, 80) << endl;

	delete tmp;
	return 0;
}
