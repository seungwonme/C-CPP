- [C++](#c)
	- [What is difference between C and C++?](#what-is-difference-between-c-and-c)
		- [C](#c-1)
		- [C++](#c-2)
			- [C++은 C에 객체지향 개념을 추가한 언어이다.](#c은-c에-객체지향-개념을-추가한-언어이다)
			- [변수 선언 및 정의 방식와 auto 키워드](#변수-선언-및-정의-방식와-auto-키워드)
			- [메모리 할당 및 해제 방식](#메모리-할당-및-해제-방식)
			- [포인터 대신 참조자 사용](#포인터-대신-참조자-사용)
			- [식별자를 갖는 것들은 모두 소속에 속한다.](#식별자를-갖는-것들은-모두-소속에-속한다)
			- [연산자라 하더라도 실제로는 함수일 수 있다.](#연산자라-하더라도-실제로는-함수일-수-있다)
		- [Things to think about](#things-to-think-about)
			- [Don't think you're the only one writing code](#dont-think-youre-the-only-one-writing-code)
			- [함수 하나가 아닌 집합체 수준 기능 목표](#함수-하나가-아닌-집합체-수준-기능-목표)
			- [객체 사용자와 작성자의 입장 분리](#객체-사용자와-작성자의-입장-분리)
			- [객체로 구현할 대상을 식별하고 관계를 규정](#객체로-구현할-대상을-식별하고-관계를-규정)
			- [미래를 고려한 설계](#미래를-고려한-설계)


# C++

## What is difference between C and C++?

### C 
`C`는 `변수` + `함수`로 구성된 절차지향적 언어이다.
`main 함수`가 프로그램의 시작점이자 종료점인 1차원적인 구조를 가지고 있다.

```c
void callee(void) 
{
	// ...
}

int main(void) 
{
	int var; // 변수

	callee(); // caller인 main 함수에서 callee 함수를 호출
	return 0;
}
```

### C++

#### C++은 C에 객체지향 개념을 추가한 언어이다.
`Object`는 밀접하게 관련된 `변수` + `함수`로 구성된 `데이터 타입`이다. 구조체를 확장한 개념이라고 생각하면 쉽다.

#### 변수 선언 및 정의 방식와 auto 키워드
```c++
// c
int var = 10;

// 자동 변수 선언 및 스택 메모리에 할당
// 하지만 아무도 사용하지 않기 때문에(안써도 auto와 같은 효과) c++에서는 auto 키워드의 의미를 변경
auto var = 10;

// c++
int var(10);

// 자료형에 의존하지 않은 프로그래밍을 위해 auto 키워드의 의미를 변경
auto var(10);
```

#### 메모리 할당 및 해제 방식
```cpp
// c
char* str = malloc(sizeof(char) * 10);
free(str);

// malloc, free 함수를 이용하여 힙 메모리 할당 및 해제

// c++
char* str = new char[10];
delete[] str;

// new, delete 연산자를 이용하여 힙 메모리 할당 및 해제
```

#### 포인터 대신 참조자 사용
```cpp
// c

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int a = 10;
	int b = 20;

	swap(&a, &b);
	return 0;
}

// c++

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	int a = 10;
	int b = 20;

	swap(a, b);
	return 0;
}
```

포인터의 지나치게 높은 자유도는 프로그램의 안정성을 떨어뜨린다. 따라서 포인터 대신 참조자를 사용하여 프로그램의 안정성을 높인다.

#### 식별자를 갖는 것들은 모두 소속에 속한다.
소속이란 `namespace`와 `class`를 의미한다.
식별자를 같은 것들은 `instance`와 `function`이 있다.
- `instance`는 `변수`와 `객체`를 의미한다.
- `function`은 `함수`와 `메소드`를 의미한다.

#### 연산자라 하더라도 실제로는 함수일 수 있다.
`연산자 오버로딩`을 통해 연산자를 함수로 정의할 수 있다.

### Things to think about

#### Don't think you're the only one writing code
- 같은 목표에 대해 한 사람이 그 목표를 이루기 위한 방법론과 여러 사람이 그 목표를 이루기 위한 방법론은 다르다.
- 혼자할 때 불필요하다고 생각하는 것이 협업할 때는 필요할 수 있다.

#### 함수 하나가 아닌 집합체 수준 기능 목표
- 집합체란 `class`, `namespace`를 의미한다.

#### 객체 사용자와 작성자의 입장 분리
- `작성자`는 사용자 편의성을 제공하기 위해 사용자의 입장을 고려하여 코드를 작성해야 하고 `사용자`가 뭔가를 훼손할 수 있는 여지를 남겨두어서는 안된다. => `객체 무결성`

#### 객체로 구현할 대상을 식별하고 관계를 규정
- 기능을 나열하고 그 기능들을 구현할 객체를 식별한다.
- 최대한 단순한 구조로 설계하는 것을 목표로 하고 객체도 최소화한다.

#### 미래를 고려한 설계
- `OOP`를 설명할 때 가장 중요한 것 중 하나가 `시점`이다.
