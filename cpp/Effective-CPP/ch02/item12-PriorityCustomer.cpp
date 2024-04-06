#include <iostream>

void	logCall(const std::string& funcName)
{
	std::cout << funcName << std::endl;
}

class Date
{
private:
	int mYear;
	int mMonth;
	int mDay;
public:
	Date()
	: mYear(0), mMonth(0), mDay(0)
	{
		logCall("Date()");
	};
	Date(int year, int month, int day)
	: mYear(year), mMonth(month), mDay(day)
	{
		logCall("Date()");
	};
	~Date()
	{
		logCall("~Date()");
	};
	void	Print()
	{
		std::cout << "Date :" << mYear << "/" << mMonth << "/" << mDay << std::endl;
	}
};

class Customer
{
private:
	std::string mName;
	Date mDate;
public:
	Customer()
	: mName("default")
	{
		logCall("Customer()");
	};
	Customer(const std::string& rhs)
	: mName(rhs)
	{
		logCall("Customer()");
	};
	Customer(const Customer& rhs)
	: mName(rhs.mName)
	{
		logCall("Customer(const Customer&)");
	};
	const Customer& operator=(const Customer& rhs)
	{
		logCall("operator=(const Customer&)");
		mName = rhs.mName;
		return *this;
	};
	~Customer()
	{
		logCall("~Customer()");
	};
	void	SetDate(const Date& date)
	{
		mDate = date;
	};
	void	Print()
	{
		std::cout << "Customer :" << mName << std::endl;
		mDate.Print();
	}
};

int	main(void)
{
	Customer c1("c1");
	c1.SetDate(Date(2023, 1, 10));

	Customer c2("c2");
	c2 = c1;

	c1.Print();
	c2.Print();
	return 0;
}
