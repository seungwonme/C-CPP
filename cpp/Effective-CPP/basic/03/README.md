# 03

## Default Parameters
- 함수 선언 시 매개변수의 기본값을 지정할 수 있다.
- 유지보수 시에 함수의 시그니처가 바뀌면 사용자가 많은 경우에는 기존에 사용하던 코드들을 모두 수정해야 하는데, 이런 경우에 기본값을 지정해두면 기존 코드들을 수정하지 않아도 된다.
- 기본값은 반드시 오른쪽부터 채워야 한다.

## Overloading
- 함수의 이름은 같지만 매개변수의 개수나 타입이 다른 함수를 여러 개 정의할 수 있다.
- Default Parameters와 함께 사용하면 모호한 호출 오류가 발생할 수 있으므로 주의해야 한다.

## Template
- 함수 다중 정의를 대체할 수 있는 문법이며 권장되는 방법이다.
- `Template`은 함수를 생성해내기 위한 근거가 되는 코드이다.

## Namespace
- C++가 지원하는 각종 요소들(변수, 인스턴스, 클래스 및 각종 선언 등)을 한 범주로 묶어주는 문법이다.
- 식별자 이름 앞에 `::`를 붙여서 사용한다.
- 전역 인스턴스나 함수는 Global Namespace에 속하며, `::`를 생략할 수 있다.
- 여러명이 작업할 때 기존 C언어의 경우 `파일 스코프`(함수 앞에 static을 선언)를 이용해 식별자 이름 충돌을 방지했지만, C++에서는 namespace를 이용해 식별자 이름을 좀 더 세분화하여 충돌을 방지할 수 있다.

## Search order of identifiers
1. 현재 블록 범위
2. 상위 블록 (최대 함수 바디)
3. 클래스 멤버
4. (상속 시) 부모 클래스 멤버
5. 최근에 선언된 전역 변수나 함수
6. using 선언된 namespace 혹은 global namespace

`local scope` -> `class scope` -> `global scope` -> `namespace scope`

## Name mangling
- C++의 식별자 이름은 컴파일러에 의해 C언어처럼 유일한 이름으로 변환된다.
- 함수 다중 정의의 작동원리
- 식별자의 실제 이름은 링크 오류를 발생시켜 확인할 수 있다.

함수 앞에 `extern "C"`를 붙이면 C언어의 식별자 규칙을 따르게 되어 맹글링이 되지 않는다.

C++에서 함수 이름 맹글링은 컴파일러 및 링커에 따라 다르다.
`g++` 컴파일러를 사용하고 있다면, `nm` 명령어를 사용하여 오브젝트 파일에 포함된 심볼들을 확인할 수 있다. `c++filt` 명령어를 사용하면 맹글링된 이름을 해석해준다.

```bash
g++ -O0 -c nameMangling.cpp
nm nameMangling.o [| c++filt]
```

## Difference between C function and C++ function
| Language | C function | C++ function |
| :--- | :--- | :--- |
| Name | testFunc | ::testFunc |
| Allow overloading | No | Yes |
| Allow default parameters | No | Yes |
| const | No | Yes |
