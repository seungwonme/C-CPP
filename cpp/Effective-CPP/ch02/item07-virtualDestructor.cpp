#include <iostream>

class TimeKeeper
{
public:
	TimeKeeper() {};
	~TimeKeeper() {};
	// 가상 소멸자가 없다면 파생 클래스의 소멸자를 호출하지 않는다.
	// 그렇기 때문에 기본 클래스로 쓰일 수 없다.
	virtual ~TimeKeeper();
};

class AtomicClock: public TimeKeeper {};
class WaterClock: public TimeKeeper {};
class WristClock: public TimeKeeper {};

TimeKeeper* getTimeKeeper() {}; // TimeKeeper 파생 클래스의 포인터 반환

class Point
{
private:
	int x;
	int y;
public:
	Point(int xCoord, int yCoord)
	: x(xCoord)
	, y(yCoord)
	{};
	~Point();
	// Point의 소멸자가 가상 소멸자로 만들어지는 순간 클래스에 별도의 자료구조가 들어간다.
	// 이 자료구조는 프로그램 실행 중에 주어진 객체에 대해 어떤 가상 함수를 호출해야 하는지를 결정하는 데 쓰이는 정보
	// 대부분 포인터의 형태를 취하며 vptr[Virtual Table Pointer]라는 이름으로 불린다.
	// 그러므로 객체의 크기가 커지게 되면서 다른 언어와의 호환성, 이식성이 떨어지고 메모리 측면에서 낭비가 생긴다.
	// 따라서 소멸자를 virtual로 선언할 때는 그 클래스에 가상 함수가 하나라도 들어있는 경우로 한정해야한다.
};

int	main(void)
{
	TimeKeeper* ptk = getTimeKeeper(); // 동적으로 할당된 객체를 얻는다.

	// ...

	delete ptk; // 자원 누수를 막기 위해 해제한다.
	return 0;
}
