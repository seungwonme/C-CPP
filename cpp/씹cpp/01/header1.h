#include <iostream>

namespace header1 {
int foo() {
	std::cout << "header1_foo\n";
	return (0);
}
void bar() {
	std::cout << "header1_bar\n";
}
}
