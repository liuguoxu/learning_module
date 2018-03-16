#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Stack {

	private:
		vector <T> elems;

	public:
		void push(T const& elem);
		T pop();
		bool is_empty();
};

template <class T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);
}

template <class T>
T Stack<T>::pop()
{
	if(elems.empty())
		throw 0;

	T tmp = elems.back();
	elems.pop_back();
	return tmp;
}

template <class T>
bool Stack<T>::is_empty()
{
	if(elems.empty())
		return true;
	return false;
}

bool compare(char left, char right)
{
	if(left == '{' && right == '}')
		return true;
	
	if(left == '[' && right == ']')
		return true;
	
	if(left == '(' && right == ')')
		return true;

	return false;
}

//栈处理括号匹配问题
int main()
{
	Stack<char> stk;
	string test = "{[(])]}";

	for(int i =0; i <= test.length(); i ++)
	{
		//左括号入栈
		if(test[i] == '{' || test[i] == '[' || test[i] == '('){
			stk.push(test[i]);
			continue;
		}

		//右括号跟栈内匹配
		if(test[i] == '}' || test[i] == ']' || test[i] == ')'){
			try {
				char tmp = stk.pop();
				if(compare(tmp, test[i]))
					continue;

				cout << "wrong compare!!"<< endl;
				return 0;
			} catch(...) {
				cout << "stack empty, wrong!!" << endl;
				return 0;
			}
		}
	}
	
	if(stk.is_empty())
		cout << "right!!"<< endl;
	else
		cout <<"wrong !!, stack is not empty"<< endl;
	return 0;	
}
