#include <iostream>
#include <string>

using namespace std;

class Girl
{
	public:
		static int Num;
		void set_info(string new_name, int new_age);

		void show_info()
		{
			cout << "name is "<< this->name <<", age is "<< this->age<< endl;
		}

		Girl()
		{
			cout << "This is a new girl!" << endl;
		}

		~Girl()
		{
			cout << name << " is gone" << endl;
			Num--;
		}
		static int get_num()
		{
			return Num;
		}
	private:
		string name;
		int age;
};

int Girl::Num = 0;

void Girl::set_info(string new_name, int new_age)
{
	name = new_name;
	age = new_age;
}

int main()
{
	Girl lily;
	lily.set_info("Lily", 17);
	lily.show_info();
}
