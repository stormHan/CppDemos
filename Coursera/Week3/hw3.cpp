#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2{
public:
	Array2();
	Array2(int _i, int _j);
	Array2(Array2& _a);

	~Array2();
	int operator ()(int _i, int _j);
	int* operator [](int _i);
	Array2& operator =(const Array2 _a);

private:
	int col;
	int row;

	int *p;
};
Array2::Array2()
{
	col = 0;
	row = 0;
	p = NULL;
}

Array2::Array2(int _i, int _j)
{
	row = _i;
	col = _j;

	p = new int[row * col];
}

Array2::Array2(Array2& _a)
{
	col = _a.col;
	row = _a.row;
	p = new int[col * row];
	memcpy(p, _a.p, sizeof(int) * col * row);
}

int Array2::operator ()(int _i, int _j)
{
	return p[_i * col + _j];
}

Array2& Array2::operator=(const Array2 _a)
{
	col = _a.col;
	row = _a.row;
	p = new int[col * row];
	memcpy(p, _a.p, sizeof(int) * col * row);

	return *this;
}

Array2::~Array2()
{
	delete[] p;

}

int* Array2::operator[](int _i)
{
	return p + _i * col;
}

int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;     b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}