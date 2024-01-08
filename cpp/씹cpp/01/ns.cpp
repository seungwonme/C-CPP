#include "header1.h"
// #include "header2.h"

// // using namespace header1;
// using namespace header2;
// int	main() {
// 	foo();  // header1 에 있는 함수를 호출
// 	bar();  // header1 에 있는 함수를 호출
// 	header1::bar();
// 	header1::foo();
// }

namespace {
// 이 함수는 이 파일 안에서만 사용할 수 있습니다.
// 이는 마치 static int OnlyInThisFile() 과 동일합니다.
int OnlyInThisFile() {
	std::cout << "hi";
	return (1);
}

// 이 변수 역시 static int x 와 동일합니다.
int only_in_this_file = 0;
}  // namespace

int main() {
  OnlyInThisFile();
  only_in_this_file = 3;
}
