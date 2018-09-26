//关于const的一些使用
#include <iostream>

using namespace std;

 
//int const 和 const int一样，表示引用对象不可修改
void quote(const int& x)
{
	cout << "original x is :" << x << endl;
	x++;
	cout << "modified x is :" << x << endl;
}

int main()
{
	int i =5;
	//const修饰p1，表示p1不能指向别的对象，但所指对象的值可以改变
	int* const p1 = &i;
	*p1 = 6;
	//cout << "p1 :" << *p1 << endl;

	//const修饰int *，表示p2所指对象的值不能改变，但可以指向别的对象
	const int* p2 = &i;
	int j = 8;
	//cout << "p2 :" << *p2 << endl;
	p2 = &j;
	//cout << "p2 :" << *p2 << endl;

	quote(i);
	cout << "after quote i is :" << i << endl;

	return 0;
}
