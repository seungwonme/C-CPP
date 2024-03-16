#include <iostream>

struct Day
{
	explicit Day(int d) 
	: val(d) {};
	int val;
};

// enum을 사용해도 되지만 int처럼 쓰이는 등의 타입 안전성 문제가 있다.
// 타입 안전성이 신경 쓰인다면 유효한 Month의 집합을 미리 정의해두는 것이 좋다.
class Month
{
public:
	static Month Jan() { return Month(1); }
	static Month Feb() { return Month(2); }
	static Month Mar() { return Month(3); }
	static Month Apr() { return Month(4); }
	static Month May() { return Month(5); }
	static Month Jun() { return Month(6); }
	static Month Jul() { return Month(7); }
	static Month Aug() { return Month(8); }
	static Month Sep() { return Month(9); }
	static Month Oct() { return Month(10); }
	static Month Nov() { return Month(11); }
	static Month Dec() { return Month(12); }
private:
	explicit Month(int m)
	: val(m) {};
	int val;
	// Month 값이 새로 생성되지 않도록 생성자가 private에 있다.
};

// struct Month
// {
// 	explicit Month(int m)
// 	: val(m) {};
// 	int val;
// };

struct Year
{
	explicit Year(int y)
	: val(y) {};
	int val;
};

class Date
{
private:
	// int mDay;
	// int mMonth;
	// int mYear;
	Day mDay;
	Month mMonth;
	Year mYear;
public:
	// Date(int day, int month, int year)
	Date(const Day& day, const Month& month, const Year& year)
	: mDay(day.val)
	, mMonth(month)
	, mYear(year.val) {};
	~Date() {};
};

int	main(void)
{
	// Date d(3, 40, 2019); // Wrong: 40 is not a valid month
	// 사용자 실수를 막기 위해 새로운 타입을 들여와 인터페이스를 강화

	Date d(Day(3), Month::Aug(), Year(2019));
	// 각각의 구조체에 이것저것을 숨겨 넣어 온전한 클래스로 만들어도 좋겠지만 타입을 적절히 새로 준비만 해도 인터페이스 사용 에러를 막는데 효과적이다.
	return 0;
}
