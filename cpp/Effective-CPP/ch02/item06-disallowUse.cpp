#include <iostream>

// 링크 시점의 에러를 컴파일 시점의 에러로 옮기기위한 클래스
class Uncopyable
{
protected:
	Uncopyable() {};
	~Uncopyable() {};
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

// class HomeForSale
class HomeForSale: private Uncopyable
{
private:
	std::string mOnly;
	// private으로 정의할 시 friend 함수 혹은 멤버 함수가 호출할 수 있다.
	// private에 선언만 해놓음으로써 링크 에러 유도
	// HomeForSale(const HomeForSale&);
	// HomeForSale& operator=(const HomeForSale&);
public:
	HomeForSale()
	{};
	HomeForSale(std::string only)
	: mOnly(only)
	{};
};

int	main(void)
{
	HomeForSale h1("Diamond");
	HomeForSale h2;

	HomeForSale h3(h1); // 복사 금지

	h2 = h1; // 복사 금지

	return 0;
}
