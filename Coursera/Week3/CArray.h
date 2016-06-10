
class CArray
{
public:
	CArray(int s = 0);
	CArray(CArray& ca);
	CArray(int len, int* e);

	void push_back(int i);
	int length();
	int* getElem(){ return elem; }

	//注意返回值一定要是引用
	//a[i] = 4 1，返回值是引用才能作为左值，第二，想修改这个值，必须用引用。
	int& operator[](const int i);
	CArray& operator=(const CArray c);

	~CArray();
private:
	int* elem;
	int m_length;
	const int max = 100;
};

void CArray::push_back(int i)
{
	if (elem)
	{
		int* p = new int[m_length + 1];
		memcpy(p, elem, sizeof(int) * m_length);
		delete[] elem;
		elem = p;
	}
	else
		elem = new int[1];

	elem[m_length++] = i;
}

int CArray::length()
{
	return m_length;
}

int& CArray::operator[](const int i)
{
	if (i >= m_length)
	{

	}
	else
	{
		return elem[i];
	}
	
}

CArray& CArray::operator=(const CArray ca)
{
	if (elem = ca.elem) return *this;

	if (ca.elem == NULL)
	{
		if (elem) delete[] elem;
		elem = NULL;
		m_length = 0;
		return *this;
	}
	if (elem) delete[] elem;
	elem = new int[ca.m_length];
	memcpy(elem, ca.elem, sizeof(int) * ca.m_length);
	m_length = ca.m_length;
	return *this;
}

//必须要写一个复制构造函数，防止两个指针指向同一片存储空间。
CArray::CArray(CArray& ca)
{
	if (!ca.elem)
	{
		elem = NULL;
		m_length = 0;
		return;
	}
	else
	{
		elem = new int[ca.length()];
		memcpy(elem, ca.elem, sizeof(int) * ca.length());
		m_length = ca.m_length;
	}
}

CArray::CArray(int len, int* e)
{
	elem = new int[len];
	memcpy(elem, e, sizeof(int) * len);
	m_length = len;
}

CArray::CArray(int s) :m_length(s)
{
	if (s == 0)
		elem = NULL;
	else
		elem = new int[s];
}

CArray::~CArray()
{
	if (elem)
		delete[] elem;
	m_length = 0;
}