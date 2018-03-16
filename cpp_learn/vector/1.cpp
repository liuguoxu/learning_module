/*vector 的基本操作！！！*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//定义int型的vector
	vector<int> v_tmp = {1,2,3};

	//定义迭代器
	vector<int>::iterator it;
	int i =0;

	//迭代打印值
	for(it = v_tmp.begin(), i=0; it != v_tmp.end(); it ++, i++)
		printf("v_tmp[%d]= %d\n",i, *it);


	//通过下标打印
	for(vector<int>::size_type ix = 0; ix != v_tmp.size(); ix ++)
		printf("%d\t", v_tmp[ix]);
	printf("\n");

	it = v_tmp.begin()+1;
	cout << *it << endl;

	it = v_tmp.end()-1;
	cout << *it << endl;

	//front(). back(), 返回第一个和最后一个元素的引用

	cout<< "front() is "<< v_tmp.front() <<", back() is "<< v_tmp.back() << endl;
}
