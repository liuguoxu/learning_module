#include <iostream>
#include "main.h"

using namespace std;

Chinese:: Chinese(string _province = "beijing", string _name = "anonymous"): \
	province(_province)
	//, name(_name)   protected不能通过初始化列表初始化！？
{
	name = _name;
	cout << "New Chinese" << endl; 
}

void Chinese:: SayHello()
{
	cout <<"Hello, i am a Chiness, my province is "<< province << endl;
}

int main()
{
	Chinese *ch = new Chinese("hainan", "zhangsan");
	Chinese *dft = new Chinese;

	ch->SayHello();
	dft->SayHello();

	ch->SetAge(18);
	ch->SetHeight(175.3);
	ch->ShowInfo();

	dft->SetAge(15);
	dft->ShowInfo();
	
	return 0;
	
}

