#include <iosfwd>
#include <memory>

class Person
{
public:
	// 주어진 매개변수로 초기화된 Person 객체를 반환한다.
	static std::shared_ptr<Person> Create(
		const std::string& name,
		const std::string& birthDate,
		const std::string& address);
	virtual ~Person() {}
	virtual std::string Name() const = 0;
	virtual std::string BirthDate() const = 0;
	virtual std::string Address() const = 0;
};
