# Chapter 04

## Item 18: Make interfaces easy to use correctly and hard to use incorrectly

### Things to Remember
- 좋은 인터페이스는 제대로 쓰기에 쉬우며 엉터리로 쓰기에 어렵다. 인터페이스를 설계할 때는 이 특성을 지닐 수 있도록 고민해야 한다.
- 인터페이스를 올바른 사용으로 이끄는 방법으로는 `인터페이스 사이의 일관성 잡아주기`, `기본 제공 타입과의 동작 호환성 유지하기`가 있다.
- 사용자의 실수를 방지하는 방법으로는 `새로운 타입 만들기`, 타입에` 대한 연산을 제한하기`, `객체의 값에 대해 제약 걸기`, `자원 관리 작업을 사용자 책임으로 놓지 않기`가 있다.
- `std::shared_ptr`은 사용자 정의 삭제자를 지원한다. 이 특징 때문에 `std::shared_ptr`은 교차 DDL 문제를 막아주며, 뮤텍스 등을 자동으로 잠금 해제하는 데 쓸 수 있다.

## Item 19: Treat class design as type design

### What to consider when designing a class
- 새로 정의한 타입의 객체 생성 및 소멸은 어떻게 이루어져야 하는가?
- 객체 초기화는 객체 대입과 어떻게 달라야 하는가?
- 새로운 타입으로 만든 객체가 `값에 의해 전달(Deep Copy)`되는 경우에 어떤 의미를 줄 것인가?
- 새로운 타입이 가질 수 있는 적법한 값에 대한 제약은 무엇으로 잡을 것인가?
- 기존의 클래스 `상속 계통망(Inheritance Graph)`에 맞출 것인가?
- 어떤 종류의 타입 변환을 허용할 것인가?
- 어떤 연산자와 함수를 두어야 의미가 있을까?
- 표준 함수들 중 어떤 것을 허용하지 말 것인가?
- 새로운 타입의 멤버에 대한 접근 권한을 어느 쪽에 줄 것인가?
- `선언되지 않은 인터페이스`로 무엇을 둘 것인가?
- 새로 만드는 타입이 얼마나 일반적인가?
- 정말로 꼭 필요한 타입인가?

### Things to Remember
- 클래스 설계는 타입 설계다. 새로운 타입을 정의하기 전에, 이번 항목에 나온 모든 고려사항을 빠짐없이 점검해 보아야 한다.

## Item 20: Prefer pass-by-reference-to-const to pass-by-value

### Slicing Problem
`pass-by-value` 방식으로 객체를 복사하는 과정에서 발생하는 문제
파생 클래스 객체가 기본 클래스 객체로서 전달되는 경우 기본 클래스의 멤버만 복사되고 파생 클래스의 멤버는 복사되지 않는다.

### Things to Remember
- `pass-by-value`보다 `pass-by-reference`를 선호하라. 대체적으로 효율적일 뿐만 아니라 복사손실 문제까지 막아준다.
- 이번 항목에서 다룬 법칙은 기본제공 타입 및 STL 반복자, 그리고 함수 객체 타입에는 맞지 않다. 이들에 대해서는 `pass-by-value`이 더 적절하다.

## Item 21: Don't try to return a reference when you must return an object

### Things to Remember
- 지역 스택 객체에 대한 포인터나 참조자를 반환하는 일, 혹은 힙에 할당된 객체에 대한 참조자를 반환하는 일, 또는 지역 정적 객체에 대한 포인터나 참조자를 반환하는 일은 그런 객체가 두 개 이상 필요해질 가능성이 있다면 절대로 하지 말아야 한다.

## Item 22: Declare data members private

### Why data members should be private

#### 문법적 일관성
- 클래스의 공개 인터페이스에 있는 것들이 함수라면 클래스 멤버에 접근하고 싶을 때 `()`를 붙여야 하는지 아닌지를 헷갈릴 수 있다.

#### 데이터 멤버의 접근성에 대해 정교한 제어
- 어떤 데이터 멤버를 `public`으로 선언하면 모두가 이 멤버에 대해 읽기 및 쓰기 접근 권한을 가지지만 이 값을 읽고 쓰는 메소드가 있다면 접근 권한을 직접 구현할 수 있다.

#### Encapsulation
- 데이터 멤버를 `private`으로 선언하면 클래스의 구현 세부사항을 완전히 감출 수 있다.
- 데이터 멤버를 함수 인터페이스 뒤에 감추게 되면 구현상의 융통성을 전부 누릴 수 있다.
- 현재의 구현을 나중에 바꾸기로 결정할 수 있는 권한을 예약하는 것이다. 만약 `public` 혹은 `protected`로 선언된 부분을 고친다면 이를 사용하는 모든 코드를 수정해야 한다.
- `캡슐화되지 않았다`라는 말은 `바꿀 수 없다`라는 말과 같다.

### Things to Remember
- 데이터 멤버는 private 멤버로 선언하자. 이를 통해 클래스 제작자는 문법적으로 일관성있는 데이터 접근 통로를 제공할 수 있고, 필요에 따라서는 세밀한 접근 제어도 가능하며, 클래스의 불변속성을 강화할 수 있을 뿐 아니라, 내부 구현의 융통성도 발휘할 수 있다.
- protected는 public보다 더 많이 보호받고 있는 것이 절대 아니다.

## Item 23: Prefer non-member non-friend functions to member functions

### 캡슐화를 많이할 수록 생기는 장점
캡슐화하는 것이 늘어나면 그만큼 밖에서 볼 수 있는 것들이 줄어든다.
그러면 그 것들을 바꿀 때 필요한 유연성이 커진다.
그렇기 때문에 이미 있는 코드를 바꾸더라도 제한된 사용자들밖에 영향을 주지 않는 융통성을 확보할 수 있다.
데이터를 접근할 수 있는 함수의 개수가 많을 수록 그 데이터의 캡슐화 정도는 낮다.

### Things to Remember
- 멤버 함수보다는 비멤버 비프렌드 함수를 자주 쓰도록 하자. 캡슐화 정도가 높아지고, 패키징 유연성도 커지며, 기능적인 확장성도 늘어난다.

## Item 24: Declare non-member functions when type conversions should apply to all parameters

### Things to Remember
- 어떤 함수에 들어가는 모든 매개변수(this 포인터가 가리키는 객체도 포함해서)에 대해 타입 변환을 해 줄 필요가 있다면, 그 함수는 비멤버여야 한다.

## Item 25: Consider support for a non-throwing swap
스왑 함수는 `Copy Constructor` 1회, `Copy Assignment Operator` 2회를 호출하기 때문에 class에 따라 성능이 크게 저하될 수 있다.

1. std::swap이 정의 타입에 대해 납득할만한 효율을 보장하지 못한다면
2. public 멤버 swap을 제공하고 이 멤버가 예외를 던지지 않도록 보장한다.
3. 클래스 혹은 템플릿이 소속되어있는 namespace에 비멤버 함수 swap을 추가하고 이 함수가 public 멤버 swap을 호출하게 만든다.
4. 새로운 클래스를 만든다면 그 클래스에 대한 특수화된 std::swap을 제공하고 이 함수가 public 멤버 swap을 호출하게 만든다.
5. 사용자 입장에서 swap을 호출할 때, swap을 호출하는 함수가 `using std::swap`을 선언하고 네임스페이스 한정 없이 swap을 호출하게 만든다.

### Things to Remember
- std::swap이 여러분의 타입에 대해 느리게 동작할 여지가 있다면 swap 멤버 함수를 제공하자. 이 멤버 swap은 예외를 던지지 않아야 한다.
- 멤버 swap을 제공했으면, 이 멤버를 호출하는 비멤버 swap도 제공하자. 클래스에 대해서는, std::swap을 특수화하자.
- 사용자 입장에서 swap을 호출할 때는, std::swap에 대한 using 선언을 넣어준 후에 네임스페이스 한정 없이 swap을 호출하자.
- 사용자 정의 타입에 대한 std 템플릿을 완전 특수화하는 것은 가능하다. 그러나 `std에 어떤 것이라도 새로 추가하지 말자.` (std는 조금 특별한 namespace이기 때문에 새로운 템플릿을 추가하면 `Undefined Behavior가 발생할 수 있다.`)
