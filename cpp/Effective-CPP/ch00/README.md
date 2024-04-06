# Chapter 00

## 선언(Declaration)
- 코드에 사용되는 어떤 대상의 이름과 타입을 컴파일러에게 알려주는 것
- 구체적인 세부사항은 선언에 포함되지 않는다.

### 시그니처(Signature)
- 함수의 반환하는 타입과 매개변수의 타입을 시그니처라고 한다.

## 정의(Definition)
- 선언에서 빠진 구체적인 세부사항을 컴파일러에게 제공하는 것

## 초기화(Initialization)
- 어떤 객체에 최초의 값을 부여하는 과정

### 생성자(Constructor)
- 사용자 정의 타입으로 생성한 객체의 경우, 초기화는 생성자에 의해 이루어진다.

#### 기본 생성자(Default Constructor)
- 매개변수가 없는 생성자
- 원래부터 매개변수가 없거나 모든 매개변수가 기본 값을 갖고 있으면 기본 생성자가 될 수 있다.

#### explicit
- 생성자 앞에 붙여서, 암시적 변환을 금지시킨다.
- 명시적 타입 변환만 허용한다.

### 복사 생성자(Copy Constructor)
- 어떤 객체 초기화를 위해 같은 타입의 다른 객체를 사용하는 생성자

### 복사 대입 연산자(Copy Assignment Operator)
- 어떤 객체에 다른 객체의 값을 복사하는 연산자

## STL 
- Standard Template Library
- Container, Algorithm 및 이들과 관련된 기능들이 집결한 결정체

## Interface
- 함수의 signature, 어떤 클래스의 접근 가능 요소같은 일반적인 설계 아이디어
