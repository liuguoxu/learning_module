#include <iostream>

using namespace std;

/*函数 和 运算符重载*/
class Money
{
	private:
		int yuan;
		int jiao;
		int fen;

	public:
		Money()
		{
			yuan = 0;
			jiao = 0;
			fen = 0;
		}
		/*重载构造函数*/
		Money(int y, int j, int f)
		{
			yuan = y;
			jiao = j;
			fen = f;
		}

		void show()
		{
			cout <<yuan <<" 元, "<< jiao<< " 角, " << fen<< " 分" << endl;
		}
		/*重载运算符*/
		Money operator+(const Money &m)
		{
			Money tmp;
			int jw = 0;
			if ((tmp.fen = this->fen + m.fen) > 10) {
				tmp.fen -= 10;
				jw = 1;
			}

			if((tmp.jiao = this->jiao + m.jiao + jw) > 10) {
				tmp.jiao -= 10;
				jw = 1;
			} else
				jw = 0;

			tmp.yuan = this->yuan + m.yuan + jw;
			return tmp;
		}
};

int main()
{
	Money m1(3,2,1), m2(1,9,3);
	m1.show();
	m2.show();
	Money m3;
	m3 = m1 + m2;
	m3.show();
}
