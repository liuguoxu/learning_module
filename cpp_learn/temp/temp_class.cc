#include <iostream>
#include "temp_class.h"

/*类模板的使用*/

template<class T> T A<T>::plus(T a, T b) {
	return a+b;
}

using namespace std;
template<class T> A<T>::A() {
	cout<<"new A"<< endl;	
}

int main()
{
	A<int> a;
	std:: cout << a.plus(2,2.5)<< endl;
	return 0;
}
