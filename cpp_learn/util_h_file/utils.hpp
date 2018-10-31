#ifndef MY_UTILS_H_
#define MY_UTILS_H_

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace utils {
	
inline int getNum()
{
	static int num = 0;

	if (num != 0 ) {
		cout << "return directlly~" << endl;
		return num;
	}

	num = 123;
	return num;
}


inline string getString()
{
	cout << getNum() << endl;
	return "abc";
}


}


#endif  //#ifndef MY_UTILS_H_
