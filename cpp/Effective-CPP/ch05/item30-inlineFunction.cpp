#include <iostream>

class Person
{
private:
	std::string name;
	int age;
public:
	Person(std::string name, int age) : name(name), age(age) {}
	~Person() {}
	std::string GetName() const { return name; }
	int GetAge() const { return age; } // 
};

int	main(void)
{
	
	return 0;
}
