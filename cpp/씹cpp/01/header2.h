#include <iostream>

namespace header2 {
int foo() {
	std::cout << "header2_foo\n";
	return (0);
}
void bar() {
	std::cout << "header2_bar\n";
}
}
