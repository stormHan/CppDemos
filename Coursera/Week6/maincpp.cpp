#include <string>
using namespace std;

//模板声明
template <class T> void Swap(T& n1, T& n2);

class tst
{
public:
	string name;
	int number;
};

template <class T1, class T2> class Pair
{
public:
	Pair(T1 k, T2 v) : key(k), value(v){};

	bool operator < (Pair p);
private:
	T1 key;
	T2 value;
};

template <class T1, class T2>
bool Pair<T1, T2>::operator < (Pair p)
{
	return key < p.key;
}

template <class T>
void print(T a)
{

}

//函数模板
template <class T>
void Swap(T& n1, T& n2)
{
	T tmp;
	tmp = n1;
	n1 = n2;
	n2 = tmp;

	T::type *p;
}

template <typename T>
T fabs(const T& a)
{
	tst::number = 1;

	T b;
	if (a < 0)
		b = -a;
	else
		b = a;

	return b;
}

//类模板
template <class T> class Queue
{

};


int main()
{
	int a = 1, b = 2;
	Swap(a, b);

	double p = 1.2, q = 3.2;
	Swap(p, q);

	double d = -1.1;
	d = fabs(d);

	Queue<int>;

	Pair<string, int> student("hjw", 23);

	return 0;
}