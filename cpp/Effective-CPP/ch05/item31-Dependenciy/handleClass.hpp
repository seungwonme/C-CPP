#include <iosfwd>

class PersonImp1; // Person의 구현 클래스에 대한 전방 선언
// Person 클래스 안에서 사용하는 것들에 대한 전방 선언
class Date; 
class Address;

class Person
{
public:
	Person(const std::string& name, const Date& birthday, const Address& addr);
	std::string Name() const;
	std::string BirthDate() const;
	std::string Address() const;
private:
	PersonImp1* pImpl; // 구현 객체에 대한 포인터
};

