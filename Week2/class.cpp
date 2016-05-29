#include <iostream>

class Complex
{
public:
	Complex(double _a, double _b);
	Complex();
	Complex(int _a);
	~Complex();

	void Hello()const{ std::cout << "hello " << std::endl; };

private:
	double a, b;
	static int c;
};

Complex::Complex(double _a, double _b)
{
	a = _a;
	b = _b;
}
Complex::Complex(int _a)
{
	a = _a;
	b = 0;
	std::cout << "constructor2 called " << std::endl;
}

Complex::Complex()
{
	a = 1;
	b = 1;
	std::cout << "constructor1 called " << std::endl;
}
Complex::~Complex()
{
	std::cout << "destructor called " << std::endl;
}

class CRectangle
{
public:
	CRectangle();
	CRectangle(int _w, int _h);
	~CRectangle();

	static void printRectangle();

private:
	int w, h;
	static int totalRectangle;
	static int totalArea;
	friend class Complex;
};

CRectangle::CRectangle()
{
	w = 1;
	h = 1;

	totalRectangle += 1;
	totalArea += w * h;
}

CRectangle::CRectangle(int _w, int _h)
{
	w = _w;
	h = _h;

	totalRectangle += 1;
	totalArea += w * h;
}

CRectangle::~CRectangle()
{
	totalRectangle -= 1;
	totalArea -= w * h;
}

void CRectangle::printRectangle()
{
	std::cout << "total number " << totalRectangle << std::endl;
	std::cout << "total area " << totalArea << std::endl;
}
int CRectangle::totalArea = 0;
int CRectangle::totalRectangle = 0;

int main()
{
	Complex c[3];
	c[1] = 1;
	std::cout << "end main " << std::endl;

	//std::cout << sizeof(double) << std::endl << sizeof(Complex) << std::endl;
	
	CRectangle r1(2, 4), r2(3, 3);

	CRectangle::printRectangle();
	
	Complex* p = NULL;
	p->Hello();

	getchar();
	return 0;
}