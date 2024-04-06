#include <iostream>
#include <vector>

class Widget
{
public:
	Widget();
	~Widget(); // 이 함수로부터 예외가 발생된다고 가정
};

void	doSomething()
{
	std::vector<Widget> v;
} // v 소멸

// 만약 10개의 Widget을 갖던 vector가 소멸 중 2번째 Widget 소멸자에서 예외가 발생한다면?

class DBConnection
{
public:
	DBConnection() {};
	~DBConnection() {};
	static DBConnection	create(); // DBConnection 객체를 반환하는 함수
	void				close(); // 연결을 닫음. 이 때 실패하면 예외를 던짐
};

class DBConn
{
private:
	DBConnection db;
	bool		bClosed;
public:
	DBConn() {};
	~DBConn()
	{
		// db.close(); // 데이터베이스 연결이 항상 닫히도록 확실히 챙기는 함수
		// 만약 예외가 발생했다면?
		// 1. 프로그램을 바로 끝낸다.
		/* try
		{
			db.close();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::abort();
		} */
		// 2. 예외를 삼켜 버린다.
		/* try
		{
			db.close();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		} */
		// 만약 예외 삼키기를 선택하기로 했다면 프로그램이 신뢰성 있게 실행을 지속할 수 있어야 한다.
		// 3.어떤 동작이 예외를 일으키면서 실패할 가능성이 있고 또 그 예외를 처리해야 할 필요가 있다면 그 예외는 소멸자가 아닌 다른 함수에서 비롯된 것이야 한다.
		if (!bClosed)
		{
			try
			{
				db.close();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				// 예외를 삼키거나 종료
			}
		}
	}
	// 소멸자가 아닌 예외를 처리할 함수
	void	close()
	{
		db.close();
		bClosed = true;
	}
};

int	main(void)
{

	return 0;
}
