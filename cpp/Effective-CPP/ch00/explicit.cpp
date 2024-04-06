#include <iostream>

class A
{
private:
	int mData;
	bool mb;
public:
	A() // 기본 생성자
	: mData(0)
	, mb(false)
	{};
};

class B
{
private:
	int mData;
	bool mb;
public:
	explicit B(int x = 0, bool b = true) // 기본 생성자
	: mData(x)
	, mb(b)
	{};
};

class C
{
private:
	int mData;
	bool mb;
public:
	explicit C(int x = 0) // 기본 생성자가 아님
	: mData(x)
	, mb(false)
	{};
};

void	doSomething(B bObject)
{
	(void) bObject;
}

int	main(void)
{
	B bObj1;

	doSomething(bObj1);

	B bObj(28);

	// doSomething(28); // Error
	doSomething(B(28));
	return 0;
}
