// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>

class Test {
	char c;

 public:
	Test(char _c) {
		c = _c;
		std::cout << "생성자 호출 " << c << std::endl;
	}
	~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};
void simple_function()
{
	Test b('b');
	// Test 지역 객체 소멸
}
int main() {
	Test a('a');
	simple_function();
	// Test 지역 객체 소멸
}
