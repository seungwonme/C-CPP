#include <iostream>
#include "MyString.hpp"

int	main(void)
{
	MyString str1("very very very long string");
	str1.Reserve(30);
	std::cout << "Capacity : " << str1.GetCapacity() << std::endl;
	std::cout << "String length : " << str1.GetLength() << std::endl;
	str1.Println();

	str1.Insert(3, "hi!");
	str1.Insert(40, "hi!");
	str1.Insert(1000, "hi!");
	std::cout << "Capacity : " << str1.GetCapacity() << std::endl;
	std::cout << "String length : " << str1.GetLength() << std::endl;
	str1.Println();

	str1.Insert(3, MyString("hi"));
	str1.Insert(40, MyString("hi"));
	str1.Insert(1000, MyString("hi"));
	std::cout << "Capacity : " << str1.GetCapacity() << std::endl;
	std::cout << "String length : " << str1.GetLength() << std::endl;
	str1.Println();

	str1.Insert(3, 'A');
	str1.Insert(40, 'A');
	str1.Insert(1000, 'A');
	std::cout << "Capacity : " << str1.GetCapacity() << std::endl;
	std::cout << "String length : " << str1.GetLength() << std::endl;
	str1.Println();

	return 0;
}
