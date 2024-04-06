# 05

## Copy Constructor
- Overloading된 생성자 중 하나로, `객체를 복사하는 생성자`이다.

### Shallow Copy
- 참조의 대상은 복사해서 늘리지 않고 `reference만 늘리는 형태`이다.
- 대상 메모리 삭제 시 `복사된 포인터 참조에 따른 오류 발생 가능성이 존재`한다.

### Deep Copy
- `복사본 자체를 새로 할당하고 복사하는 방식`이다.

### When use Deep Copy?
- 포인터를 멤버로 가지며 동적 할당 및 해제하는 기능을 갖는 클래스의 경우 `Deep Copy`를 사용한다.
- `Copy Constructor`, `Copy Assignment Operator`을 정의해야 한다.

## Conversion Constructor
- 정의 시 `컴파일러에 의해 묵시적인 변환을 발생`시키는 생성자이다.
- 묵시적 변환이 발생할 때 컴파일러에 따라 `Temporary Object`가 생성/소멸될 수 있다.
- `explicit` 키워드를 사용하여 `묵시적 변환을 막을 수 있다.`

## Temporary Object
- Class가 함수의 반환 자료형이 될 경우 `Temporary Object`가 생성된다. => 비효율의 원인
- Class가 매개변수나 반환 자료형으로 사용될 경우 가급적 `const reference`로 선언하는 것이 좋다.
- Java의 `Garbage Collector`가 참조 관계를 파악하여 메모리를 해제할 정도로 중요한 문제이다.
