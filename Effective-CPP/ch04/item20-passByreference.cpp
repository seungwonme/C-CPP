#include <iostream>

class Person
{
private:
	std::string mName;
	std::string mAddress;
public:
	Person(std::string name, std::string address)
		: mName(name)
		, mAddress(address)
	{
		std::cout << "Person constructor" << std::endl;
	};
	Person(const Person& other) // copy constructor
		: mName(other.mName)
		, mAddress(other.mAddress)
	{
		std::cout << "Person copy constructor" << std::endl;
	}
	Person& operator=(const Person& other) // copy assignment operator
	{
		if (this != &other)
		{
			mName = other.mName;
			mAddress = other.mAddress;
		}
		std::cout << "Person copy assignment operator" << std::endl;
		return *this;
	}
	virtual ~Person()
	{
		std::cout << "Person destructor" << std::endl;
	};
};

class Student : public Person
{
private:
	std::string mSchoolName;
	std::string mSchoolAddress;
public:
	Student(Person person, std::string schoolName, std::string schoolAddress)
		: Person(person)
		, mSchoolName(schoolName)
		, mSchoolAddress(schoolAddress)
	{
		std::cout << "Student constructor" << std::endl;
	};
	virtual ~Student()
	{
		std::cout << "Student destructor" << std::endl;
	};
	Student(const Student& other) // copy constructor
		: Person(other)
		, mSchoolName(other.mSchoolName)
		, mSchoolAddress(other.mSchoolAddress)
	{
		std::cout << "Student copy constructor" << std::endl;
	}

	Student& operator=(const Student& other) // copy assignment operator
	{
		if (this != &other)
		{
			Person::operator=(other);
			mSchoolName = other.mSchoolName;
			mSchoolAddress = other.mSchoolAddress;
		}
		std::cout << "Student copy assignment operator" << std::endl;
		return *this;
	}
};
	
// bool validateStudent(const Student& student)
bool validateStudent(Student student)
{
	// validate student
	return true;
}

int	main(void)
{
	Student plato(Person("Plato", "Athens"), "Academy", "Athens");

	std::cout << "------Before validateStudent------" << std::endl;
	bool platoIsOK = validateStudent(plato);
	std::cout << "------After validateStudent-------" << std::endl;
	return 0;
}
