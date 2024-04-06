#include <iostream>

template<typename T>
class NamedObject
{
private:
	std::string& mName;
	const T mObjectValue;
public:
	NamedObject(const std::string name, const T& value)
	: mName(name)
	, mObjectValue(value)
	{};
};

int	main(void)
{
	std::string newDog("Bogdong");
	std::string oldDog("Huchu");

	NamedObject<int> p(newDog, 2);
	NamedObject<int> s(oldDog, 36);

	p = s;
	// string& 멤버 변수의 재참조는(재정의가 아님!!) 불가하므로 컴파일 에러
	return 0;
}
