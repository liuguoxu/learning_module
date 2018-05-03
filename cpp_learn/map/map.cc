#include <map>
#include <string>
#include <iostream>

using namespace std;

typedef map<int, string> MapInt2String;

int main()
{
	MapInt2String tmp;
	tmp.insert(pair<int, string>(1, "studeng_one"));
	tmp.insert(pair<int, string>(2, "studeng_two"));
	tmp.insert(pair<int, string>(3, "studeng_three"));

	MapInt2String::iterator iter;
	for(iter = tmp.begin();iter != tmp.end(); iter++) {
		cout << iter->first << ": " << iter->second <<endl;
	}

	return 0;
}
