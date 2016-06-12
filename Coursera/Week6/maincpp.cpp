

template <class T>
void Swap(T& n1, T& n2)
{
	T tmp;
	tmp = n1;
	n1 = n2;
	n2 = tmp;
}

int main()
{
	int a = 1, b = 2;
	Swap(a, b);

	double p = 1.2, q = 3.2;
	Swap(p, q);

	return 0;
}