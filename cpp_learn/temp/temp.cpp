//模板 function 的用法
#include <iostream>

using namespace std;

template <typename T>

T getmax(T a, T b) {
	T res;
	res = (a>b)? a:b;
	return res;
}

int main()
{
	int a =3, b =4;

	cout << getmax(a, b)<< endl;

	cout << getmax("hello", "hella") << endl;
}
