#include <iostream>

class Widget
{
private:
	int *mpData;
public:
	Widget()
	{
		mpData = new int;
		*mpData = 0;
	};
	Widget(int rhs)
	{
		mpData = new int;
		*mpData = rhs;
	}
	~Widget()
	{
		delete mpData;
	};
	/* // 1. 안전하지 않게 구현된 대입 연산자
	Widget& operator=(const Widget& rhs)
	{
		delete mpData;
		mpData = new int;
		*mpData = *rhs.mpData;
		// 만약 this->mpData == rhs.mpData 라면
		return *this;
	}; */
	// 2. Identity test를 추가하여 안전하게 구현된 대입 연산자
	/* Widget& operator=(const Widget& rhs)
	{
		if (this == &rhs) // Identity test
			return *this;
		delete mpData;
		mpData = new int;
		*mpData = *rhs.mpData;
		return *this;
	}; */
	/* // 3. 문장 순서를 바꾸어 안전하게 구현된 대입 연산자
	Widget& operator=(const Widget& rhs)
	{
		int *mpDataOrig = mpData; // 기존의 mpData를 저장
		mpData = new int;
		*mpData = *rhs.mpData;
		delete mpDataOrig; // 기존의 mpData를 삭제
		return *this;
	}; */
	/* // 4. Copy and Swap 기법을 사용한 안전하게 구현된 대입 연산자
	Widget& operator=(const Widget& rhs)
	{
		Widget temp(rhs); // rhs의 사본을 만듦
		swap(temp); // this와 temp를 교환
		return *this;
	}; */
	// 복사 생성자를 통해 rhs의 사본을 만들고, swap을 통해 this와 temp를 교환 (4와 똑같음, 명확성과 줄 수를 교환)
	Widget& operator=(Widget rhs)
	{
		swap(rhs); // this와 temp를 교환
		return *this;
	};
	void swap(Widget& rhs)
	{
		std::swap(mpData, rhs.mpData);
	};
};

int	main(void)
{
	Widget w;

	w = w; // self-assignment

	// a[i] = a[j]; // 자기 대입의 가능성이 있음
	// *px = *py; // 자기 대입의 가능성이 있음
	return 0;
}
