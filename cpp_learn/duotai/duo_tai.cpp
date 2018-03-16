#include <iostream>
using namespace std;


/*多态性*/
class A
{
	public:
		void first()
		{
			cout << "1!"<< endl;
		}
		virtual void second()
		{
			cout << "2!" << endl;
		}
};

class B : public A
{
	public:
		void first()
		{
			cout << "3!" << endl;	
		}
		void second()
		{
			cout << "4!" << endl;
		}
};


int main()
{
	A a;
	B b;
	a.first();
	a.second();
//	b.first();
//	b.second();

	A *p;
	p = &b;
	p->first();
	p->second();
}
