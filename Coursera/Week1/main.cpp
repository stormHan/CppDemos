#include <stdio.h>
#include <stdlib.h>

//����ָ��
int myCompare(const void* a, const void* b)
{
	unsigned int *p, *q;
	p = (unsigned int*)a;
	q = (unsigned int*)b;

	return (*p) % 10 - (*q) % 10;
}

//�������ü�ָ��
void swap(int &a, int &b)
{
	int temp;
	temp = a; a = b; b = temp;
}

//������Ϊ�����ķ���ֵ
int n = 4;
int& setValue() { return n; }

//
int main(int argc, char** argv)
{
	//�����в���
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

	//���� ���õı�����ԭʼ����ʼ����һ����
	double d = 4, b = 5;
	double &r1 = d;
	double &r2 = r1;

	r1 = 6;
	printf("%f\n", d);
	r2 = 7;
	printf("%f\n", d);

	setValue() = 40;
	printf("%d\n", n);

	//new �ؼ��֣� ���ص���һ��ָ�룬 ������Ǻ����sizeof(int) * N ��С���ڴ棬�൱��C�����е�malloc
	int* p = new int[100];
	delete[]p;

	//��������inline�� ���ں�������Ƚϼ򵥣������ô����ֱȽ϶�ĺ�����Ϊ�˼��ٺ�������ʱ����ջ�Ķ��⿪�������趨��һ�ֺ������ơ�
	//C++ ��Ч�����������
	
	
	return 0;
}