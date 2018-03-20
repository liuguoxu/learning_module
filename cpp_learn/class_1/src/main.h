#ifndef __MAIN_H__
#define __MAIN_H__

#include <string>

using namespace std;

class Animal {
	public:
		virtual void SayHello() = 0;
};

class Human: public Animal {
	public:
		void SetAge(int _age) {
			age = _age;
		}

		void SetHeight(double _height) {
			height = _height;
		}

		void ShowInfo() {
			cout << "Name is "<< name << endl;
			cout << "Age is "<< age <<endl;
			cout << "Height is "<< height << endl;
		}
	protected:   //protected类型可被子类调用
		string name;
		int age;
		double height;
};

class Chinese: public Human {
	public:
		Chinese(string _province, string _name);	
		void SayHello();
	private:
		string province;
};


#endif