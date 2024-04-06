// 2. 객체 지향 개념의 C++

/* 
C++는 객체 지향 프로그래밍을 지원하는데, 이는 코드를 객체 단위로 모듈화하여 코드의 재사용성과 유지 보수성을 높인다.
클래스와 객체를 사용하여 데이터와 해당 데이터를 처리하는 함수를 묶어 하나의 유기적인 단위로 만든다.
상속, 캡슐화, 다형성 등의 개념을 통해 코드의 유연성을 증가시킨다.
*/

#include <iostream>

class Base
{
private:
	int mData;
public:
	Base(int data): mData(data) {}
	virtual ~Base() {}
	void			PrintData() { std::cout << mData << std::endl; }
	virtual void	Polymorphism() { std::cout << "Base" << std::endl; }
};

class Derived : public Base
{
public:
	Derived(int data): Base(data) {}
	virtual ~Derived() {}
	virtual void	Polymorphism() { std::cout << "Derived" << std::endl; }
};

int	main(void)
{
	Derived d(42);
	d.PrintData();

	Base *b = &d;
	b->Polymorphism();
	return 0;
}
