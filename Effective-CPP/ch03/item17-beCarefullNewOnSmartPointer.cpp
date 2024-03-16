#include <iostream>

class Widget
{
public:
	Widget() {}
	~Widget() {}
};

int priority()
{
	// 처리 우선순위를 반환
	return 1;
}

void processWidget(std::shared_ptr<Widget> pw, int priority)
{
	// 우선순위가 높은 작업을 먼저 처리	
}

int	main(void)
{
	// processWidget(new Widget, priority());
	// new Widget을 std::shared_ptr<Widget>으로 암시적 형변환이 없다.

	// processWidget(std::shared_ptr<Widget>(new Widget), priority());
	// 컴파일러는 processWidget 호출 코드를 만들기 전에 매개변수로 넘겨지는 인자를 평가하는 순서를 밟는다.
	// priority() 호출, new Widget 표현식 실행, std::shared_ptr<Widget> 생성자 호출
	// C++ 컴파일러의 경우 함수 인자 평가 순서를 보장하지 않는다.
	// 1. new Widget 표현식 실행
	// 2. priority() 호출
	// 3. std::shared_ptr<Widget> 생성자 호출

	// 만약 priority()가 예외를 던진다면 new Widget으로 할당된 메모리는 누수된다.
	// 자원이 생성되는 시점과 그 자원이 자원 관리 객체로 넘어가는 시점의 예외가 끼어들 수 있기 때문이다.

	// 따라서 Widget을 생성해서 스마트 포인터에 저장하는 별도의 문장을 사용하는 것이 좋다.
	std::shared_ptr<Widget> pw(new Widget);
	processWidget(pw, priority());
	return 0;
}
