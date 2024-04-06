#include <iostream>

class Widget
{
private:
public:
	Widget();
	~Widget();
};

int	main(void)
{
	Widget w;

	w = w; // self-assignment

	// a[i] = a[j]; // 자기 대입의 가능성이 있음
	// *px = *py; // 자기 대입의 가능성이 있음
	return 0;
}
