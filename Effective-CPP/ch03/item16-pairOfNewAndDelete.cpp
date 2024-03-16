#include <iostream>
#include <unistd.h>

// export MallocStackLogging=1 find leaks after unset MallocStackLogging
// if you want more info about leaks use gcc -g option
// while true; do leaks a.out; sleep 1; done;
void	leak(void)
{
	system("leaks --list a.out");
}

void f()
{
	std::string* stringArr = new std::string[10];

	// ...
	
	delete stringArr;
	// Undefined behavior
}

// typedef로 정의된 어떤 타입의 배열은
// 사용자에게 delete[] 책임을 전가한다.
// 되도록 객체의 배열에 대해서는 typedef를 사용하지 말자.
// 대신 vector 같이 안전한 컨테이너를 사용하자.
typedef std::string AddressLines[4];

void typedefine()
{
	std::string* pal = new AddressLines;
	// ...
	delete pal;
	// Undefined behavior
}

int	main(void)
{
	atexit(leak);
	f();
	typedefine();

	sleep(5); 

	return 0;
}
