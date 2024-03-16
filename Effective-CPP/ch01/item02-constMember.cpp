#include <iostream>

class GamePlayer
{
private:
	static const int NumTurns = 5; // 상수 선언
	// #define NUM_TURNS 5 // 클래스 상수를 정의할 때 쓸 수 없을 뿐더러 유효범위가 없기 때문에 캡슐화의 혜택을 받을 수 없다.
	// enum { NumTurns = 5 }; enum hack: 동작 방식이 const보다 #define과 비슷하다.
	int scores[NumTurns]; // 상수를 사용하는 부분
public:
	GamePlayer(const int a, const int b)
	{
		scores[0] = a;
		scores[1] = b;
	};
	const int* GetNumTurnsAddress() const { return &NumTurns; };
};

/*
어떤 상수의 유효 범위를 클래스로 한정하고자 할 때는 그 상수를 멤버로 만들어야하고
그 상수의 사본 개수가 한 개를 넘지 못하게 하고 싶다면 static 멤버로 만들어야 한다.
*/

// 정의가 아닌 선언만 있으면 컴파일러가 상수의 주소를 알 수 없다.
// '선언' 이 아니라 '정의' 이다. 그런데 왜 값이 주어지지 않았을까?
// 클래스 상수의 정의는 구현 파일에 두며, 헤더 파일에는 두지 않는다.
// 정의에는 상수의 초기값이 있으면 안되는데,
// 왜냐하면 클래스 상수의 초기값은 해당 상수가 선언된 시점에 바로 주어지기 때문이다!
// const int GamePlayer::NumTurns; // 상수 정의

int	main(void)
{
	GamePlayer gp(1, 2);
	std::cout << gp.GetNumTurnsAddress() << std::endl;
	return 0;
}
