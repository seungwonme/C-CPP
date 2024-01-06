#include <iostream>
#include <string>
#include "MyString.hpp"

// export MallocStackLogging=1 find leaks after unset MallocStackLogging
// if you want more info about leaks use gcc -g option
// while true; do leaks minishell; sleep 1; done;
void	leak(void)
{
	system("leaks --list myString");
}

int	main(void)
{
	atexit(leak);
	MyString str1("very very very long string");
	/* str1.Reserve(30);
	std::cout << "String length : " << str1.GetLength() << std::endl;
	std::cout << "Capacity : " << str1.GetCapacity() << std::endl;
	str1.Println();

	str1.Insert(3, "hi!");
	str1.Insert(40, "hi!");
	str1.Insert(1000, "hi!");
	std::cout << "String length : " << str1.GetLength() << std::endl;
	std::cout << "Capacity : " << str1.GetCapacity() << std::endl;
	str1.Println();

	str1.Insert(3, MyString("hi!"));
	str1.Insert(40, MyString("hi!"));
	str1.Insert(1000, MyString("hi!"));
	std::cout << "String length : " << str1.GetLength() << std::endl;
	std::cout << "Capacity : " << str1.GetCapacity() << std::endl;
	str1.Println();

	str1.Insert(3, 'A');
	str1.Insert(40, 'A');
	str1.Insert(1000, 'A');
	std::cout << "String length : " << str1.GetLength() << std::endl;
	std::cout << "Capacity : " << str1.GetCapacity() << std::endl;
	str1.Println();

	std::cout << "----------------------------------------------------------------" << std::endl;

	std::string str2("very very very long string");
	str2.reserve(30);
	std::cout << "String length : " << str2.length() << std::endl;
	std::cout << str2 << std::endl;

	str2.insert(3, "hi!");
	str2.insert(29, "hi!");
	str2.insert(32, "hi!");
	std::cout << "String length : " << str2.length() << std::endl;
	std::cout << str2 << std::endl;

	str2.insert(3, std::string("hi!"));
	str2.insert(38, std::string("hi!"));
	str2.insert(41, std::string("hi!"));
	std::cout << "String length : " << str2.length() << std::endl;
	std::cout << str2 << std::endl;

	str2.insert(3, "A");
	str2.insert(40, "A");
	str2.insert(46, "A");
	std::cout << "String length : " << str2.length() << std::endl;

	std::cout << str2 << std::endl;
	str1.Println(); */

	// Assignment operator가 없었다면 Shallow copy => 소멸자 함수에서 이중 delete 발생
	MyString a;
	a = str1;
	std::cout << a << '\n';
	a.Reserve(30);
	a.SetContent("dasd");
	std::cout << a << '\n';
	return 0;
}
