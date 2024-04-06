#include <iostream>

// 모든 거래에 대한 기본 클래스
class Transaction
{
public:
	Transaction()
	{
		// ...
		logTransaction(); // 마지막 동작으로, 이 거래를 로깅하기 시작
	};
	virtual void logTransaction() const = 0;
	// 타입에 따라 달라지는 로그 기록을 만든다.

	// main문의 내용처럼 문제가 발생했을 때의 대처 방법
	explicit Transaction(const std::string& logInfo) // 파생 클래스의 생성자들에게 필요한 로그 정보를 Transaction의 생성자로 넘겨야 한다는 규칙
	{
		// ...
		logTransaction(logInfo);
	}
	void	logTransaction(const std::string& logInfo) const; // 이제는 비가상 함수다.
};

class BuyTransaction
{
public:
	virtual void logTransaction() const;
	// 각자 타입에 맞는 거래내역 로깅을 구현
};

class SellTransaction
{
private:
	static std::string createLogString(/* param */);
public:
	SellTransaction(/* param */)
	: Transaction(createLogString(/* param */)) // 로그 정보를 기본 클래스 생성자로 넘긴다.
	{};
};

int	main(void)
{
	BuyTransaction b; // 생성자에서 BuyTransaction의 logTransaction이 아닌 Transaction의 logTransaction이 호출된다 !
	// 기본 클래스의 생성자가 호출될 동안에는, 가상 함수는 절대로 파생 클래스 쪽으로 내려가지 않는다.
	// 그 대신, 객체 자신이 기본 클래스 타입인 것처럼 동작한다.
	// 기본 클래스 생성자는 파생 클래스 생성자보다 앞서서 실행되기 때문에 기본 클래스 생성자가 돌아가는 시점에 파생 클래스 데이터 멤버는 초기화되지 않는 상태인 것이 핵심
	// 파생 클래스 객체의 기본 클래스 부분이 생성되는 동안, 그 객체의 타입은 기본 클래스이다.
	return 0;
}
