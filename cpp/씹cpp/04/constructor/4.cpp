#include <iostream>

class Date
{
	int year_;
	int month_;  // 1 부터 6 까지.
	int day_;    // 1 부터 31 까지.

 public:
	void ShowDate();

	Date()
	{
		std::cout << "기본 생성자 호출!" << std::endl;
		year_ = 2023;
		month_ = 11;
		day_ = 6;
	}

	Date(int year)
	{
		std::cout << "인자 1 개인 생성자 호출!" << std::endl;
		year_ = year;
		month_ = 11;
		day_ = 6;
	}

	Date(int year, int month)
	{
		std::cout << "인자 2 개인 생성자 호출!" << std::endl;
		year_ = year;
		month_ = month;
		day_ = 6;
	}

	Date(int year, int month, int day)
	{
		std::cout << "인자 3 개인 생성자 호출!" << std::endl;
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

void Date::ShowDate()
{
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_ << " 일 입니다 " << std::endl;
}
int main()
{
	Date day = Date();
	Date day1(2023);
	Date day2(2023, 11);
	Date day3(2023, 10, 31);

	day.ShowDate();
	day1.ShowDate();
	day2.ShowDate();
	day3.ShowDate();

	return 0;
}
