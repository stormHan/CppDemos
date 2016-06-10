#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;

	}
	// 在此处补充你的代码
	Complex& operator= (const string s)
	{
		string tmp;
		int j = 0;
		for (; j < s.size(); ++j)
		{
			if (s[j] != '+' && s[j] != 'i')
			{
				tmp.push_back(s[j]);
				continue;
			}
			else if (s[j] == '+')
			{
				r = atof(tmp.c_str());
				tmp = "";
				continue;
			}
			else
			{
				i = atof(tmp.c_str());
			}
		}
		return *this;
	}
};


//int main() {
//	Complex a;
//	a = "3+4i"; a.Print();
//	a = "5+6i"; a.Print();
//	return 0;
//}