#include <stdio.h>

// struct에는 변수만 멤버로 선언할 수 있음
typedef struct USERDATA
{
	int mAge;
	char mName[32];
	void (*PrintData)(struct USERDATA*);
} USERDATA;

// struct USERDATA와 밀접하게 관련된 함수
void PrintUser(USERDATA* user)
{
	printf("%d, %s\n", user->mAge, user->mName);
}

int	main(void)
{
	USERDATA user = {24, "seunan", PrintUser};
	// PrintUser 함수는 자료구조 USERDATA에 종속적이다.
	// 헤더 파일에서 USERDATA를 선언하고, 소스 파일에서 PrintUser 함수를 구현하는 것처럼
	// 따로따로 관리하지 않고 문법적으로 하나로 묶어서 관리할 수 있을까? 생각에서 나온 것이
	// 멤버 함수 포인터이다.

	user.PrintData(&user);
	// user가 부른 함수에 user를 인자로 넘겨주는 것이 어색하다.
	// 이걸 생략하도록 만들자라고 생각해서 탄생한 것이 C++의 멤버 함수(Method)다.
	// 시점 상으로 현재는 제작자가 코드를 작성하는 시점이고 미래는 사용자가 코드를 사용하는 시점이다.
	// 제작자가 코드를 작성하는 시점에 USERDATA user의 주소값을 알 수 없기 때문에 문법적으로 this를 만들었다.
	// C++에서는 인자로 &user를 넘겨주는 것을 생략할 수 있게 하는 대신 기본적으로 this를 매개변수로 넘겨준다.
	return (0);
}
