#include <iostream>

using namespace std;
class BOX {
	public:
		double height;
		double breadth;
		double length;

		double get_vol();
};

double BOX::get_vol()
{
	return height*breadth*length;
}

int main()
{
	BOX box1;
	box1.height = 5.0;
	box1.length = 6.0;
	box1.breadth = 7.0;

	double vol = box1.get_vol();

	cout<<"vol is "<<vol << endl;
	return 0;
}
