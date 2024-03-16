# Chapter 05

## Item 26: Postpone variable definitions as long as possible.

### When defining a variable, the cost
1. The cost of constructing that object
2. The cost of destroying that object

### Things to Remember
- 변수 정의는 늦출 수 있을 때까지 늦추자. 프로그램이 더 깔끔해지며 효율적이게 된다.

## Item 27: Minimize casting.

### C style casting (Old style)
- (T)expression
- T(expression)

### C++ style casting (New style)
- const_cast<T>(expression)
- dynamic_cast<T>(expression)
- reinterpret_cast<T>(expression)
- static_cast<T>(expression)

#### const_cast
- 객체의 상수성(constness)을 없애는 용도로 사용

#### dynamic_cast
- 런타임에 안전한 다운 캐스팅(safe downcasting)을 위해 사용
- 런타임 비용이 높은 연산자

#### reinterpret_cast
- 포인터를 int로 바꾸는 등의 하부 수준 변환(low-level conversions)을 위해 사용
- 결과는 구현 환경에 의존적이기에 이식성이 낮다.

#### static_cast
- 암시적 변환(implicit conversions)을 강제로 진행하기 위해 사용

### Things to Remember
- 다른 방법이 가능하다면 캐스팅은 피하자. 특히 수행 성능에 민감한 코드에서 `dynamic_cast`는 몇 번이고 다시 생각해보자. 설계 중에 캐스팅이 필요해졌다면, 캐스팅을 쓰지 않는 다른 방법을 찾아보자.
- 캐스팅이 어쩔 수 없이 필요하다면, 함수 안에 숨길 수 있도록 해보자. 이렇게 하면 최소한 사용자는 자신의 코드에 캐스팅을 넣지 않고 이 함수를 호출할 수 있게 된다.
- 캐스팅을 사용할 때는 C++ style 캐스팅을 사용하자. C style 캐스팅은 캐스팅의 목적을 알기 어렵고, C++ style 캐스팅보다 위험하다.

## Item 28: Avoid returning "handles" to object internals.

### Things to Remember
- 어떤 객체의 내부 요소에 대한 핸들(참조자, 포인터, 반복자)을 반환하는 것을 피하자. 캡슐화 정도를 높이고, 상수 멤버 함수가 객체의 상수성을 유지한 채로 동작할 수 있도록 하며, 무효참조 핸들이 생기는 경우를 최소화할 수 있다.

## Item 29: Strive for exception-safe code.

### Conditions of exception safety

#### Leak no resources
- 자원관리 전담 클래스를 사용하면 간단하고 안전하게 자원을 관리할 수 있다.
  
#### Don’t allow data structures to become corrupted

##### Basic guarantee
- 함수 동작 중에 예외가 발생하면, 실행중인 프로그램에 관련된 모든 것들을 유효한 상태로 유지하겠다는 보장
- 사용자 입장에서 프로그램의 상태가 정확히 어떤지는 알 수 없다. (전적으로 제작자에게 달려있음)

##### Strong guarantee
- 함수 동작 중에 예외가 발생하면, 함수 호출 전 상태로 되돌리겠다는 보장
- 이런 함수를 호출하는 것은 `atomic` 동작이라고 할 수 있다.
- 사용자 입장에서 예측할 수 있는 프로그램의 상태가 두 개 밖에 안되기 때문에 사용하기 쉽다.

##### Nothrow guarantee
- 약속한 동작은 언제나 끝까지 완수하는 함수, 즉 예외를 절대로 던지지 않겠다는 보장
- 기본 제공 타입의 연산자들이 이런 보장을 한다.

### Copy and swap
- 객체의 상태를 `all or nothing` 방식으로 유지하는 방법

### Things to Remember
- 예외 안전성을 갖춘 함수는 실행 중 예외가 발생되더라도 자원을 누출시키지 않으며 자료구조를 더럽힌 채로 두지 않는다. 이런 함수들이 제공할 수 있는 예외 안전성 보장은 `Basic guarantee`, `Strong guarantee`, `Nothrow guarantee` 이 있다.
- 강력한 예외 안전성 보장은 `copy and swap` 방법을 써서 구현할 수 있지만, 모든 함수에 대해 강력한 보장이 실용적인 것은 아니다.
- 어떤 함수가 제공하는 예외 안전성 보장의 강도는, 그 함수가 내부적으로 호출하는 함수들이 제공하는 가장 약한 보장을 넘지 않는다.

## Item 30: Understand the ins and outs of inlining.
- `Inline` 함수는 컴파일러에 대해 `request`하는 것이지, `command`하는 것은 아니다. (컴파일러가 `inline`을 무시할 수도 있다.)
- `inline`: 함수 호출 위체에 호출된 함수를 끼워 넣는 작업을 프로그램 실행 전에 한다.
  - virtual: 어떤 함수를 호출할지 결정하는 작업을 프로그램 실행 중에 한다.
- `inline`을 붙이지 않아도 암시적으로도 명시적으로도 되는 경우가 있다.

### Implicit inline
- 클래스 내부 정의된 함수는 암시적으로 `inline`이다.

### Explicit inline
- 함수 선언에 `inline`을 붙이면 명시적으로 `inline`이다.

### How inline works
- 대부분의 빌드 환경에서 `inline`을 컴파일 도중에 수행하기 때문에 대체적으로 헤더 파일에 정의해야 한다. (마찬가지로 `Template`도 헤더 파일에 정의해야 한다.)
- `Template`을 만들었는데 모든 함수가 `inline` 함수였으면 싶은 경우 그 `Template`에 `inline`을 붙이면 된다.

### Things to Remember
- 함수 인라인은 작고, 자주 호출되는 함수에 대해서만 하는 것으로 묶어두자. 이렇게 하면 디버깅 및 라이브러리의 바이너리 업그레이드가 용이해지고, 자칫 생길 수 있는 코드 부풀림 현상이 최소화되며, 프로그램의 속력이 더 빨리질 수 있는 여지가 최고로 많아진다.
- 함수 템플릿이 대개 헤더 파일에 들어간다는 일반적은 부분만 생각해서 이들을 `inline`으로 선언하면 안된다.

## Item 31: Minimize compilation dependencies between files.

### Handle class
- pimpl(pointer to implementation)을 사용하는 클래스
- `Interface`와 `Implementation`을 분리하기 위해서 `Dependencies on declarations`을 `Dependencies on definitions`로 바꾸자.
- 객체 참조자 및 포인터로 충분한 경우에는 직접 객체를 쓰지 말고 `Forward declaration`을 사용하자.
- 할 수 있으면 클래스 정의 대신 클래스 선언에 최대한 의존하도록 만들자.
- 선언부와 정의부에 대해 별도의 헤더 파일을 제공하자. (선언 부에서 `iosfwd` 헤더(iostream 관련 함수 및 클래스들의 선언부만 구성된 헤더)를 사용하면 헤더 파일을 더욱 작게 만들 수 있다.)

### Interface class
- 어떤 기능을 나타내는 인터페이스를 추상 기본 클래스를 통해 마련해놓고, 이 클래스로부터 파생 클래스를 만들 수 있게 하는 클래스
- 파생이 목적이기 때문에 데이터 멤버, 생성자도 없고 가상 소멸자와 인터페이스를 구성하는 순수 가상 함수만 있다.
- 객체 생성 수단이 최소한 하나는 있어야 하는데 이 문제를 파생 클래스와 생성자 역할을 대신하는 `Factory function(Virtual constructor)`을 호출함으로써 해결한다. `Factory function`은 주어진 클래스의 인터페이스를 지원하는 객체를 동적으로 할당한 후, 그 객체의 포인터를 반환한다.
- 구현 방법
    1. 인터페이스 클래스로부터 인터페이스 명세를 물려받은 후에, 그 인터페이스에 들어 있는 가상 함수를 모두 구현하는 클래스를 만든다.
    2. 다중 상속

### Things to Remember
- 컴파일 의존성을 최소화하는 작업의 배경이 되는 가장 기본적인 아이디어는 `definition` 대신에 `declaration`에 의존하게 만드는 것이다. 이 아디이어에 기반한 두 가지 접근 방법은 `Handle class`와 `Interface class`이다.
- 라이브러리 헤더는 그 자체로 모든 것을 갖추어야 하며 선언부만 갖고 있는 형태여야 한다. 이 규칙은 템플릿이 쓰이거나 쓰이지 않거나 동일하게 적용하자.
