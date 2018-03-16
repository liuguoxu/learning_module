#include <iostream>

int add(int x, int y)
{
	return x+y ;
}

using namespace std;
int main()
{
	int x = 5;
	int y = 1;

	for(int i =0;i<=3;i++) {
		x = add(x, y);
	}

	cout << x <<endl;
	return 0;
}
