#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> foo;
	foo.push_back("asd");
	foo.push_back("qwer");
	foo.push_back("zxc");

	cout << "foo size = "<< foo.size() << endl;
	cout << "foo capacity = "<< foo.capacity() << endl;

	//与空vector交换 达到清空效果
	vector<string>().swap(foo);
	cout << "foo size = "<< foo.size() << endl;
	cout << "foo capacity = "<< foo.capacity() << endl;

	
	return 0;
}
