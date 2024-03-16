#include <iostream>

class FontHandle
{
public:
	FontHandle()
	{
		std::cout << "FontHandle()" << std::endl;
	};
	~FontHandle()
	{
		std::cout << "~FontHandle()" << std::endl;
	};
};

void	releaseFont(FontHandle fh)
{
	std::cout << "releaseFont()" << std::endl;
}

class Font
{
private:
	FontHandle f;
public:
	explicit Font(FontHandle fh)
	: f(fh)
	{
		std::cout << "Font(FontHandle)" << std::endl;
	};
	~Font()
	{
		std::cout << "~Font()" << std::endl;
		releaseFont(f);
	};
	FontHandle get() const // 명시적 변환 함수
	{
		return f;
	};
	operator FontHandle() const // 암시적 변환 함수
	{
		return f;
	};
};

void	changeFontSize(FontHandle fh, int newSize)
{
	std::cout << "changeFontSize()" << std::endl;
}

FontHandle	getFont()
{
	FontHandle fh;
	return fh;
}

int	main(void)
{
	Font f(getFont());
	int newFontSize = 5;
	// changeFontSize(f.get(), newFontSize); // 명시적 변환 함수를 사용하여 FontHandle을 얻음
	changeFontSize(f, newFontSize); // 명시적 변환 함수를 사용하여 FontHandle을 얻음

	FontHandle f2 = f; // 원래 의도는 Font 객체를 복사하려는 것이었지만, FontHandle로 암시적 변환되어 FontHandle 객체가 생성됨
	return 0;
}
