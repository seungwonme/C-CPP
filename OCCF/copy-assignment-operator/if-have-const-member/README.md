# 대입 연산자 operator=를 private 영역에 선언함으로써 클래스의 객체 간에 대입을 시도할 때 컴파일 타임 에러를 발생시키는 방법

const Human &operator=(const Human &rhs);를 private 영역에 선언하고 정의하지 않음으로써, 이 클래스의 인스턴스가 다른 인스턴스로 대입되는 것을 컴파일러 단계에서 막음 

이는 `객체의 불변성을 유지`하고 싶거나, `객체 간의 대입이 의미 없거나 위험할 때 유용`

h1 = h2; 라는 대입을 시도하면, operator=가 private으로 선언되어 있기 때문에 컴파일 타임에 에러가 발생

이는 의도한 동작이며, 클래스의 설계자가 객체 간 대입을 원하지 않는 것을 명확하게 표현하는 방법

복사 생성자 Human(const Human &rhs) : name(rhs.name) {}를 정의함으로써 객체의 복사는 허용하지만, 대입은 허용하지 않는 클래스의 세밀한 제어가 가능


## 예외

```bash
error: 'this' argument to member function 'operator=' has type 'const std::string' (aka 'const basic_string<char>'), but function is not marked const
class Human
      ^~~~~
in-private.cpp:24:8: note: in implicit copy assignment operator for 'Human' first required here
    h1 = h2;
```

std::string 멤버 변수 name이 const로 선언되어 있기 때문에, 이 멤버 변수에 대한 대입을 시도할 때 컴파일러는 해당 연산을 수행할 수 없기에 에러를 발생시킴

대입 연산자 operator=의 기본 구현은 `모든 멤버 변수를 대입하려고 시도`하는데, const 멤버 변수는 대입 후에도 그 값이 변경되지 않아야 함을 의미

따라서, 컴파일러는 const 멤버 변수를 포함하는 클래스에 대한 기본 대입 연산자를 생성할 수 없음

에러 메시지에서 const std::string (이 경우는 name 변수)에 대한 operator=가 const로 표시되지 않았다고 지적하는 것은, 실제로는 Human 클래스의 객체 간 대입을 시도할 때 name 멤버 변수에 대한 대입을 시도하게 되는데, name이 const로 선언되어 있어서 이 대입이 불가능하다는 것을 의미

이러한 상황은 클래스 내에서 대입 연산자를 명시적으로 private으로 선언하지 않아도, const 멤버 때문에 자동으로 대입 연산이 금지되는 결과를 가져옴

따라서, 앞서 언급한 const Human &operator=(const Human &rhs);를 private에 선언하는 방법은 이 경우 필요하지 않을 수 있음

const 멤버 변수가 포함된 클래스에 대해서는 컴파일러가 자동으로 대입 연산을 금지하기 때문

이러한 접근 방식은 클래스의 객체가 생성된 후에는 해당 객체의 상태를 변경할 수 없게 하고 싶을 때 유용하며, 객체의 불변성을 강조할 때 사용할 수 있음

## 정리
CPP05 Bureaucrat 클래스를 정의할 때 멤버 데이터 변수 중 const std::string name;을 선언하였음
이 때문에 복사 생성자는 초기화 시 name 멤버 변수를 초기화할 수 있지만, 대입 연산자는 name 멤버 변수에 대한 대입을 시도하게 되는데, 이는 불가능한 동작이므로 컴파일러가 에러를 발생시킴

생각해본 복사 대입 연산자를 구현하기 위한 2가지 방법
1. const Human &operator=(const Human &rhs);를 private에 선언하고 정의하지 않음
2. const_cast<std::string &>(name) = rhs.name;을 사용하여 name 멤버 변수에 대한 대입을 시도

첫 번째 방법의 경우, OCCF에서 필수로 구현해야하는 복사 대입 연산자를 private에 선언만 했기 때문에 구현하지 않은 게 됨 -> `OCCF 구현 요구사항을 만족하지 못함`

두 번째 방법의 경우, const_cast를 사용하여 const 멤버 변수에 대한 대입을 시도하게 되는데, 이는 `const_cast를 사용하여 const 멤버 변수에 대한 대입을 시도하는 것은 안전하지 않은 방법`이라고 판단
이는, `객체의 불변성을 깨는 행위`와 `사용자가 프로그램의 동작을 예측하기 어렵게 만드는 행위`이기 때문

따라서, 
