#include <iostream>
#include <string>

using namespace std;

int main()
{

class A{
public:
	A(int a) {
		num = a;
	}

	A(int a, string s) {
		num = a;
		str = s;
	}

	void print() {
		cout << "num:" << num << "," << "str:" << str << endl;
	}

private:
	int num;
	string str;
};

	A a(1);
	a.print();

	A b(125,"aaa");
	b.print();

	return 0;
}
