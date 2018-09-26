#include <iostream>

using namespace std;
class Child1 {
public:
	Child1(): i(10) {cout << "Child i: " << i << endl;}
	int i;

	virtual void f() {}
};

int main()
{
	Child1 a;
	Child1 b;

	int *p1 = (int *)&a;
	int *p2 = (int *)&b;

	cout << p1 << " " << p2 << endl;
	p1++;
	cout << *p1 << " " << *p2 << endl;

	int *p3 = (int *)*p2;
	cout << p3 << endl;
}
