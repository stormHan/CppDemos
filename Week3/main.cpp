#include <iostream>

#include "CArray.h"

using namespace std;

class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0);
	

	Complex operator+(const Complex c1);
	Complex operator-(const Complex c1);

	friend ostream& operator<<(ostream& o, Complex& c);

	double real;
	double imag;
};

Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}

Complex Complex::operator+(const Complex c1)
{
	return Complex(real + c1.real, imag + c1.imag);
}

Complex Complex::operator-(const Complex c1)
{
	return Complex(this->real - c1.real, this->imag - c1.imag);
}


//运算符重载相当于是一个函数，也需要提前声明。
//Complex operator+ (const Complex c1, const Complex c2);

//编写一个长度可变的字符串类String
class String
{
public:
	String() :str(NULL){};
	const char* c_str(){
		return str;
	}

	char* operator=(const char* s);

	~String();

private:
	char* str;
};

char* String::operator=(const char* s)
{
	if (str)
	{
		delete[] str;
	}
	if (s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	else
	{
		str = NULL;
	}
	return str;
}

String::~String()
{
	if (!str) delete[] str;
}

ostream& operator<<(ostream& o, Complex& c)
{
	o << c.real << "+" << c.imag << "i";
	return o;
}

istream& operator>>(istream& i, Complex& c)
{
	//先读进string里面再分别剥离出real imag
	return i;
}

class CDemo
{
public:
	CDemo(int _n) :n(_n){};

	CDemo operator++();
	CDemo operator++(int);

	//强制类型转化
	operator int(){ return n; }
	
	friend CDemo operator--(CDemo&);
	friend CDemo operator--(CDemo&, int);
private:
	int n;
};

//前置
CDemo CDemo::operator++()
{
	n++;
	return *this;
}

CDemo operator--(CDemo& d)
{
	d.n--;
	return d;
}
//后置
CDemo CDemo::operator++(int)
{
	CDemo temp (*this);
	n++;
	return temp;
}

CDemo operator--(CDemo& d, int)
{
	CDemo t = d;
	d.n--;
	return t;
}


int main(int argc, char** argv)
{
	Complex c1(1, 2), c2(3, 5), c3, c4;
	c3 = c1 + c2;
	c4 = c1 - c2;
	std::cout << c3.real << " " << c4.imag << std::endl;

	String s;
	
	s = "good luck!";
	std::cout << s.c_str() << std::endl;

	char* w = "hello world";
	std::cout << w << std::endl;


	int a = 1;
	int b = a;
	std::cout << &a << " " << &b << std::endl;
	

	CDemo d(5);
	cout << (d++) << ",";
	cout << d << ",";
	cout << (++d) << ",";
	cout << d << endl;
	cout << (d--) << ",";
	cout << d << ",";
	cout << (--d) << ",";
	cout << d << endl;
	
	getchar();


	return 1;
}


//int main()
//{
//	CArray a;
//	for (int i = 0; i < 5; ++i)
//	{
//		a.push_back(i);
//	}
//	CArray a2, a3;
//	a2 = a;
//
//	for (int i = 0; i < a.length(); ++i)
//	{
//		std::cout << a[i] << " ";
//	}
//	a2 = a3;
//	for (int i = 0; i < a2.length(); ++i)
//	{
//		std::cout << a2[i] << " ";
//	}
//	std::cout << std::endl;
//	a[3] = 100;
//	CArray a4(a);
//	for (int i = 0; i < a4.length(); ++i)
//	{
//		std::cout << a4[i] << " ";
//	}
//
//	getchar();
//	return 0;
//}

//重载成普通函数。

//Complex operator+ (const Complex c1, const Complex c2)
//{
//	return Complex(c1.real + c2.real, c1.imag + c2.imag);
//}
//
