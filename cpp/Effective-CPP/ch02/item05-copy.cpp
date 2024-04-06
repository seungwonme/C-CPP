#include <iostream>

template<typename T>
class NamedObject
{
private:
	std::string mName;
	T mObjectValue;
public:
	NamedObject(const char* name, const T& value)
	{
		mName = name;
		mObjectValue = value;
	}
	NamedObject(const std::string& name, const T& value)
	{
		mName = name;
		mObjectValue = value;
	}
};

int	main(void)
{
	// NamedObject<int> noArg; // 인자가 있는 생성자를 넣을 경우 기본 생성자가 생기지 않는다.

	NamedObject<int> no1("Smallest Prime Number", 2);
	NamedObject<int> no2(no1); // 여기서 컴파일러가 만든 복사생성자를 호출한다.

	return 0;
}
