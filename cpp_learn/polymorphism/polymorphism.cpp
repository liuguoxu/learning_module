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


void pf(A &c)
{
	c.first();
	c.second();
}

int main()
{
	A a;
	B b;
//	a.first();
//	a.second();
//	b.first();
//	b.second();

	A *p;
	p = &b;
	//虚函数不会被过早绑定，所以second会输出子类的结果
//	p->first();
//	p->second();

	pf(a);
	pf(b);
}
