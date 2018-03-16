#include <iostream>

using namespace std;

class Test{
	public:
		int x;
		void print()
		{
			cout << "hahaha " <<endl;
		}
};

int main()
{
	/*tmp 指针为空，但print()里未对具体对象做操作，输出是可以执行的*/
	Test *tmp = NULL;
	tmp->print();
}
