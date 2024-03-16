# 04

## What is Object?
- OOP(Object Oriented Programming)에서 소프트웨어(소스코드)를 구성하는 기본 단위
- 변수 및 그와 관련한 Method가 모여서 이뤄진 하나의 `집합체`
- C++에서는 `Class`로 표현하며, C언어의 `Struct`와 유사하다. (Struct는 접근 제어, 메소드 등이 없다.)

## Declaration and Definition

C++에서는 Interface(Delcaration)와 Implementation(Definition)을 분리를 통해 모듈식 프로그래밍과 코드 재사용을 용이하게 한다.

### Declaration
- 선언은 `프로그램에게 해당 이름의 식별자가 존재한다는 것을 알려주는 것`이다. (컴파일러에게 알려주는 것)
- 보통 헤더파일에 선언을 작성한다.

### Definition
- 정의는 `식별자의 존재를 선언하고, 해당 식별자에 대한 메모리를 할당하는 것`이다. (컴파일러에게 알려주고, 메모리를 할당하는 것)
- 보통 소스파일에 정의를 작성한다.

## this
- 현재 시점: 제작자가 코드를 작성하는 시점
- 미래 시점: 사용자가 코드를 사용하는 시점

현재 시점에서 미래 시점의 `Instance`를 가리키는 포인터
object.c 파일에 잘 정리되어 있다.

## Class
- 관계에 관해 생각하지 않는다면 `함수를 포함하는 구조체`라고 생각하면 된다.
- 생성자, 소멸자 등 `문법상 자동으로 호출되는 함수`가 존재한다.
- C++는 struct는 class로 대체할 수 있기 때문에 존재하지 않는 것으로 볼 수 있다.
- `구성요소(변수나 함수)를 멤버`라고 부른다.

### Access modifier
- `public`: 외부에서 접근 가능
- `private`: 외부에서 접근 불가능
- `protected`: 외부에서 접근 불가능, 상속받은 자식 클래스에서 접근 가능

### Method
- `멤버 함수는 클래스 인스턴스의 메모리 공간을 소모하지 않는다.` => Name Mangling 예외가 아니다.
- 여러 인스턴스가 각각 멤버 함수 코드를 별도로 가지지 않는다.
- `클래스 멤버 함수라도 결국 C언어의 함수처럼 존재한다.`

#### Const Method
- `Const Method`는 멤버 함수의 상수화를 의미한다.

#### Virtual Method
- `Virtual Method`는 상속을 통해 재정의할 수 있는 Method이다.

### Static Member
- 소속이 Class member로 제한되었을 뿐 사실상 전역 변수나 함수와 동일하다. => `Class를 namespace처럼 사용`
- 전역 변수를 사용하지 않을 수 있는 장점이 있다.
- 일반 Method와 달리 인스턴스 선언없이 호출가능하며 `this` 포인터를 사용할 수 없다.
- Multi-thread 환경에서는 주의해야 한다.

### This Pointer
- `This Pointer`는 클래스의 실제 인스턴스를 가리키는 포인터이다.
- 모든 Method는 숨겨진 첫 번째 인자로 `this`를 가지고 있다.

### Constructor
- `Contructor`는 객체가 생성되는 시점에 자동으로 호출되는 Method이다.
- 객체의 생성은 `인스턴스 선언 및 new 연산에 따른 동적 생성` 두 경우다.
- Overloading이 가능하다.
- 전역 인스턴스가 존재할 경우 main 함수보다 먼저 호출된다.

#### Default Constructor
- `Default Constructor`는 매개변수가 없는 생성자를 의미한다.
- Class에 Constructor가 없을 경우, 컴파일러가 자동으로 생성해준다.

#### Copy Constructor
- `Copy Constructor`는 객체를 복사하는 생성자를 의미한다.
- 객체를 복사하는 방법은 `얕은 복사`와 `깊은 복사`가 있다.

#### Move Constructor

#### Conversion Constructor
- `Conversion Constructor`는 매개변수가 하나인 생성자를 의미한다.
- 묵시적 변환을 통해 임시 객체가 생성될 가능성이 있다.

#### Delegating Constructors
- `Delegating Constructors`는 생성자가 다른 생성자를 호출하는 것을 의미한다.

### Destructor
- `Destructor`는 객체가 소멸되는 시점에 자동으로 호출되는 Method이다.
- Overloading이 불가능하다.
- main 함수가 끝난 후에도 호출될 수 있다.

### Things to remember
- `Contructor`와 `Destructor`는 반환 타입이 없으며 문법에 따라 자동으로 호출된다.
- 절대로 실패할 수 없는 코드만 작성해야 한다.
- Dynamic memory allocation은 가급적 사용하지 않는다.
- 객체 자체와 관련되지 않은 코드는 작성하지 않는다.
