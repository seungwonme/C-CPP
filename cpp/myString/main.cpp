#include "MyString.hpp"
using namespace std;

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
	str1.Println();
	return 0;
}
