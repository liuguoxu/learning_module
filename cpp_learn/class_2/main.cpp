#include <iostream>
#include <string>

using namespace std;

class House {
	public:
		House(string name = "default_house"):name_(name) {
			cout << "I am a house my name is " << name_ << endl;
		}

		string getName() {return name_;}
	private:
		string name_;
};

class Wife {
	public:
		Wife(House h, string name = "yizhi"):h_(h), name_(name) {
			cout << "I am wife, my house is " << h_.getName() << endl;
		}

		string getName() {return name_;}
	private:
		House& h_;
		string name_;
};

//不在初始化列表中的h_ 优先初始化，后面可用h_去初始化w_
class Person {
	public:
		Person():w_(h_) {
			cout << "I am a person, my wife is " << w_.getName()  << endl;
		}
		
	private:
		House h_;
		Wife w_;
};


int main()
{
	Person p;
	return 0;
}
