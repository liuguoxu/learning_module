#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	
	string str = "qwerty";
	const char *p = str.c_str();
	cout << p<<endl;

	char ol[22] = "llllpo";
	str = ol;
	cout << str<< endl;

	strcpy(ol, "123");
	cout << str << endl;
	return 0;
}
