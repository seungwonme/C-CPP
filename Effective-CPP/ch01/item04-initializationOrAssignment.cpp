#include <iostream>
#include <list>

class PhoneNumber
{
private:
	/* data */
public:
	PhoneNumber(/* args */);
	~PhoneNumber();
};

class ABEntry
{
private:
	std::string mName;
	std::string mAddress;
	std::list<PhoneNumber> mPhones;
	int mNumTimesConsulted;
public:
	// ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones)
	// {
	// 	// 모두 '초기화'가 아닌 '대입'을 하고 있다.
	// 	mName = name;
	// 	mAddress = address;
	// 	mPhones = phones;
	// 	mNumTimesConsulted = 0;
	// }
	// C++ 규칙에 의하면 어떤 객체든 그 객체의 데이터 멤버는 생성자가 실행되기 전에 초기화되어야 한다.
	/*
	또한, 대입만 사용한 버전의 경우 mName, mAddress, mPhones, mNumTimesConsulted 에 대해 기본 생성자를 호출해서
	초기화를 미리 해놓은 후에 생성자에서 곧바로 새로운 값을 대입하고 있다.
	따라서, 먼저 호출된 기본 생성자에서 해 놓은 초기화 작업은 무의미하게 된다.
	*/
	ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones)
	: mName(name)
	, mAddress(address)
	, mPhones(phones)
	, mNumTimesConsulted(0) // 비용의 차이는 없지만 모든 클래스 멤버를 리스트에 넣는 습관을 들임으로써 실수를 방지할 수 있다.
	{};
	// 이렇게 초기화 리스트를 사용하면 '초기화'가 아닌 '대입'을 하지 않아도 된다.
};

int	main(void)
{

	return 0;
}
