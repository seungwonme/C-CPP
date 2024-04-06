#include <iostream>

class Point
{
private:
	int x;
	int y;
public:
	Point(int x, int y) : x(x), y(y) {}
	~Point() {};
	void	SetX(int x) { this->x = x; }
	void	SetY(int y) { this->y = y; }
	int		GetX() const { return x; }
	int		GetY() const { return y; }
};

struct RectData
{
	Point ulhc; // upper left-hand corner
	Point lrhc; // lower right-hand corner
};

class Rectangle
{
private:
	RectData* pData;
public:
	Rectangle(RectData& rhs) : pData(&rhs) {}
	const Point& UpperLeft() const { return pData->ulhc; } 
	// Rectangle 객체 내부를 수정하지 않기 때문에 const가 붙었으나, Point 객체는 수정할 수 있기에 모순 발생
	const Point& LowerRight() const { return pData->lrhc; }
};

int	main(void)
{
	RectData data = { Point(0, 0), Point(100, 100) };

	Rectangle rec(data);

	rec.UpperLeft().SetX(50);
	// 반환값을 const 주면 수정 불가

	std::cout << "Upper left x: " << rec.UpperLeft().GetX() << std::endl;
	std::cout << "Upper left y: " << rec.UpperLeft().GetY() << std::endl;
	std::cout << "Lower right x: " << rec.LowerRight().GetX() << std::endl;
	std::cout << "Lower right y: " << rec.LowerRight().GetY() << std::endl;
	return 0;
}
