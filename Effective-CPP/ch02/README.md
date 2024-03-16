# Chapter 02

## Item 05: Know what functions C++ silently writes and calls

### C++이 자동으로 생성하는 함수들
- default constructor
- copy constructor
- copy assignment operator
- destructor

copy assignment operator와 copy constructor는 원본 객체의 비정적 데이터를 사본 객체 쪽으로 복사하는 것이 전부다.

### Things to remember
- 컴파일러는 경우에 따라 클래스에 대해 기본 생성자, 복사 생성자, 복사 대입 연산자, 소멸자를 암시적으로 만들어 놓을 수 있다.

## Item 06: Explicitly disallow the use of compiler-generated functions you do not want

### Things to remember
- 컴파일러에서 자동으로 제공하는 기능을 허용하지 않으려면, 대응되는 멤버 함수를 private로 선언하고 구현하지 않으면 된다. Uncopyable과 비슷한 기본 클래스를 쓰는 것도 한 방법이다.

## Item 07: Declare destructors virtual in polymorphic base classes

### Things to remember
- 다형성을 가진 기본 클래스에는 반드시 가상 소멸자를 선언해야 한다. 즉, 어떤 클래스가 가상 함수를 하나라도 갖고 있으면, 이 클래스의 소멸자도 가상 소멸자이어야 한다.
- 기본 클래스로 설계되지 않았거나 다형성을 갖도록 설계되지 않은 클래스에는 가상 소멸자를 선언하지 말아야 한다.

## Item 08: Prevent exceptions from leaving destructors

### Things to remember
- 소멸자에서는 예외가 빠져나가면 안된다. 만약 소멸자 안에서 호출된 함수가 예외를 던질 가능성이 있다면, 어떤 예외이든지 소멸자에서 모두 받아낸 후에 삼켜버리든지 프로그램을 끝내든지 해야 한다.
- 어떤 클래스의 연산이 진행되다가 던진 예외에 대해 사용자가 반응해야 할 필요가 있다면, 해당 연산을 제공하는 함수는 보통의 함수(즉, 소멸자가 아닌 함수)로 만들어야 한다.

## Item 09: Never call virtual functions during construction or destruction

### Things to remember
- 생성자 혹은 소멸자 안에서 가상 함수를 호출하지 말자. 가상 함수라고 해도, 지금 실행 중인 생성자나 소멸자에 해당되는 클래스의 파생 클래스 쪽으로는 내려가지 않기 때문이다.

## Item 10: Have assignment operators return a reference to *this

### Things to remember
- 대입 연산자는 *this의 참조자를 반환하도록 만들어라

## Item 11: Handle assignment to self in operator=

`Self assignment`란, 어떤 객체가 자기 자신에 대해 대입 연산자를 적용하는 것을 말한다.

### Things to remember
- `operator=`을 구현할 때, 어떤 객체가 그 자신에 대입되는 경우를 제대로 처리하도록 만들자. 원복 객체와 복사 대상 객체의 주소를 비교해도 되고, 문장의 순서를 적절히 조정할 수도 있으며, `Copy and Swap` 기법을 써도 된다.
- 두 개 이상의 객체에 대해 동작하는 함수가 있다면, 이 함수에 넘겨지는 객체들이 사실 같은 객체인 경우에 정확하게 동작하는지 확인하자.

## Item 12: Copy all parts of an object

### Copying Functions
- copy constructor
- copy assignment operator

기본적인 동작: 복사되는 객체가 갖고 있는 데이터를 빠짐없이 복사한다.

### Things to remember
- 객체 복사 함수는 주어진 객체의 모든 데이터 멤버 및 모든 기본 클래스 부분을 빠뜨리지 말고 복사해야 한다.
- 클래스의 복사 함수 두 개를 구현할 때, 한쪽을 이용해서 다른 쪽을 구현하려는 시도는 절대 하지 말자. 대신, 공통된 복사 코드를 별도의 함수로 빼내서 두 복사 함수가 모두 이 함수를 호출하게 하자.
