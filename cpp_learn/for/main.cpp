#include <iostream>

using namespace std;

int main()
{
	double prices[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

	//c11 new
	for(double x : prices)
		cout << x << endl;
}
