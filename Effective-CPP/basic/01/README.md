# 01

## Instance
- 사전적 의미는 `예시` 또는 `경우`를 의미한다. => 구체적인 사례
- C++에서는 `변수` 대신 `Instance`라고 표현한다.

```cpp
int a; // int 형식에 대한 Instance a
```

## IO Stream
- `iostream` 클래스 인스턴스가 표준 입출력 장치를 추상화
- `<<`, `>>` 연산자를 시각적 의미로 활용해 직렬화 구현
- 직렬화란 1차원적 선형구조로 정보를 스트리밍하는 형태를 의미한다.

### Difference between I/O operation in C and C++

```cpp
// c
int var;

// printf 함수에 형식 지정자를 사용
printf("%s", "Hello World");

// scanf 함수에 형식 지정자를 사용
scanf("%d", &var);

// c++
// cout 객체가 자료형을 추론하여 출력
std::cout << "Hello World" << std::endl;

// cin 객체가 자료형을 추론하여 입력
std::cin >> var;
```
