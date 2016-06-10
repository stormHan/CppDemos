#include <iostream>

class CShape
{
public:
	virtual float Area() = 0;
	virtual void printInfo() = 0;

private:
};

class CRectangle : public CShape
{
public:
	virtual float Area();
	virtual void printInfo();

	float w, h;
};

float CRectangle::Area()
{
	return w * h;
}

void CRectangle::printInfo()
{
	std::cout << "CRectangle : " << Area() << std::endl;
}

class CCircle :public CShape
{
public:
	virtual float Area();
	virtual void printInfo();

	float r;
};

float CCircle::Area()
{
	return  3.14 * r * r;
}

void CCircle::printInfo()
{
	std::cout << "CCircle : " << Area() << std::endl;
}

class CTriangle : public CShape
{
public:
	virtual float Area();
	virtual void printInfo();

	float e1, e2, e3;
};

float CTriangle::Area()
{
	float t = (e1 + e2 + e3) / 2.0;

	return  sqrt(t * (t - e1) * (t - e2) * (t - e3));
}

void CTriangle::printInfo()
{
	std::cout << "CTriangle : " << Area() << std::endl;
}

int MyCompare(const void* s1, const void* s2)
{
	float a1, a2;
	CShape** p1 = (CShape**)s1;
	CShape** p2 = (CShape**)s2;
	a1 = (*p1)->Area();
	a2 = (*p2)->Area();

	if (a1 < a2)
		return 0;
	else
		return 1;
}

/*
	实际上，我们用一个基类指针数组存放指向各种派生类对象的指针，然后遍历该数组，就能对各个派生类对象做各种操作，是很常用的做法
*/
int main()
{
	CShape* cshapes[100];
	CRectangle* pr;
	CCircle* pc;
	CTriangle* pt;
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char c;
		std::cin >> c;
		switch (c)
		{
		case 'R': 
			pr = new CRectangle();
			std::cin >> pr->w >> pr->h;
			cshapes[i] = pr;
			break;

		case 'C':
			pc = new CCircle();
			std::cin >> pc->r;
			cshapes[i] = pc;
			break;
		case 'T':
			pt = new CTriangle();
			std::cin >> pt->e1 >> pt->e2 >> pt->e3;
			cshapes[i] = pt;
			break;
		default:
			break;
		}
	}

	qsort(cshapes, n, sizeof(CShape*), MyCompare);
	

	for (int i = 0; i < n; ++i)
	{ 
		cshapes[i]->printInfo();
	}

	getchar();
	return 0;
}
