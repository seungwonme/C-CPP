#include <iostream>

class Test
{
private:
	int x;
	int y;
public:
	Test(int x)
	: x(x) 
	{
		if (x > 100)
		{
			this->x = 100;
		}
	};

	Test(int x, int y)
	: Test(x) // 생성자 위임을 사용하면 코드 중복을 회피할 수 있으며 초기화 리스트에 하나의 생성자만 작성할 수 있다.
	{
		this->y = y;
		if (y > 200)
		{
			this->y = 100;
		}
	};
	~Test();
};

int	main(void)
{
	Test t(10, 20);
	return 0;
}
