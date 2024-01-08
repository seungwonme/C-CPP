#include <iostream>

class Date
{
	int year_;
	int month_;  // 1 부터 12 까지.
	int day_;    // 1 부터 31 까지.

 public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	// 해당 월의 총 일 수를 구한다.
	int GetCurrentMonthTotalDays(int year, int month);

	void ShowDate();

	// 생성자 : 객체 생성시 자동으로 호출되는 함수
	// /* 클래스 이름 */ (/* 인자 */) {}
	Date(int year, int month, int day)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

// "Date::" 을 함수 이름 앞에 붙여주게 되면 이 함수가 "Date 클래스의 정의된 함수" 라는 의미를 부여, "Date::"가 없다면 멤버 함수가 아닌 일반적인 함수로 인식
// 예외적으로 나중에 배울 템플릿 클래스의 경우 모두 클래스 내부에 작성하게 됩니다.
void Date::SetDate(int year, int month, int day)
{
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month)
{
	static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month != 2)
		return month_day[month - 1];
	else if (year % 4 == 0 && year % 100 != 0)
		return 29;  // 윤년
	else
		return 28;
}

void Date::AddDay(int inc)
{
	while (true)
	{
		// 현재 달의 총 일 수
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		// 같은 달 안에 들어온다면;
		if (day_ + inc <= current_month_total_days)
		{
			day_ += inc;
			return;
		}
		else
		{
			// 다음달로 넘어가야 한다.
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc)
{
	AddYear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate()
{
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_ << " 일 입니다 " << std::endl;
}

int main()
{
	// Date day;
	// day.SetDate(2011, 3, 1); // SetDate를 사용하지 않는다면 쓰레기값이 들어간다 => 생성자의 필요성

	Date day(2011, 3, 1);         // 암시적 방법 (implicit)
	// Date day = Date(2012, 3, 1);  // 명시적 방법 (explicit)

	day.ShowDate();

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31);  // 윤년
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();
	return 0;
}

