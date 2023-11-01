#include <iostream>

using namespace std;

int maximum[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
	int year_;
	int month_;
	int day_;

public:
	void SetDate(int year, int month, int date)
	{
		year_ = year;
		month_ = month;
		day_ = date;
	}
	void AddDay(int inc)
	{
		day_ += inc;
		while (day_ > maximum[month_])
		{
			month_ += 1;
			if (month_ == 13)
			{
				year_ += 1;
				month_ -= 12;
			}
			day_ -= maximum[month_];
		}
	}

	void AddMonth(int inc)
	{
		month_ += inc;
		while (month_ > 12)
		{
			year_ += 1;
			month_ -= 12;
		}
	}

	void AddYear(int inc)
	{
		year_ += inc;
	}

	void ShowDate()
	{
		cout << year_ << "년 " << month_ << "월 " << day_ << "일\n";
	}
};

int main(void)
{
	Date date;

	date.SetDate(2023, 10, 30);

	date.ShowDate();
	date.AddDay(93);

	date.ShowDate();
	date.AddYear(100);

	date.ShowDate();
	date.AddYear(100);
	return (0);
}
