//shared_ptr  de shi yong
#include <iostream>
#include <memory>

int main()
{
	int *p = new int(30);
	std::shared_ptr<int> sp1 = std::make_shared<int>(10);
	std::shared_ptr<int> sp2(p);
	std::shared_ptr<int> sp3(sp1);

	std::cout << "sp1 value:" << *sp1 << "count:" << sp1.use_count() << std::endl;

	delete p;
	std::cout << "sp2 value:" << *sp2 << "count:" << sp2.use_count() << std::endl;
	std::cout << "sp3 value:" << *sp3 << "count:" << sp3.use_count() << std::endl;
}
