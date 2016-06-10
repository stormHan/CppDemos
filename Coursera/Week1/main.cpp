#include <stdio.h>
#include <stdlib.h>

//函数指针
int myCompare(const void* a, const void* b)
{
	unsigned int *p, *q;
	p = (unsigned int*)a;
	q = (unsigned int*)b;

	return (*p) % 10 - (*q) % 10;
}

//利用引用简化指针
void swap(int &a, int &b)
{
	int temp;
	temp = a; a = b; b = temp;
}

//引用作为函数的返回值
int n = 4;
int& setValue() { return n; }

//
int main(int argc, char** argv)
{
	//命令行参数
	for (int i = 0; i < argc; ++i)
	{
		printf("%s\n", argv[i]);
	}

	int a[5] = { 10, 2, 88, 79, 5 };

	qsort(a, 5, sizeof(unsigned int), myCompare);

	for (int i = 0; i < 5; ++i)
	{
		printf("%d  ", a[i]);
	}

	//引用 引用的变量和原始变量始终是一回事
	double d = 4, b = 5;
	double &r1 = d;
	double &r2 = r1;

	r1 = 6;
	printf("%f\n", d);
	r2 = 7;
	printf("%f\n", d);

	setValue() = 40;
	printf("%d\n", n);

	//new 关键字， 返回的是一个指针， 分配的是后面的sizeof(int) * N 大小的内存，相当于C语言中的malloc
	int* p = new int[100];
	delete[]p;

	//内联函数inline， 对于函数本身比较简单，但调用次数又比较多的函数，为了减少函数调用时，入栈的额外开销。而设定的一种函数机制。
	//C++ 对效率上是最讲究的
	
	
	return 0;
}