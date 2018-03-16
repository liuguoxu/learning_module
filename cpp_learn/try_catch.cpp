#include <iostream>

using namespace std;


/*异常抛出和捕获*/
double divd(int a, int b)
{
	if(b ==0) {
		//throw 0;
		throw "b is zero!";
		cout << "after throw" << endl;
	}
	
	return a/b;
}

int main()
{
	int x =50;
	int y =0;

	try	{
		double res = divd(x, y);
		cout << res<< endl;
	} catch(const int msg) {
		cout <<"catch int ! "<< msg <<endl;
	} catch(const char *msg) {
		cout << "catch string !"<<msg << endl;
	}

	return 0;
}
