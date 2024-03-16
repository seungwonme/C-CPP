#include <iostream>

class CTextBook
{
private:
	char *mpText;
	mutable std::size_t mTextLength; // 바로 직전에 계산한 문자열의 길이
	mutable bool mLengthIsValid; // 문자열의 길이가 유효한지 여부
	// mutable 키워드를 명시함으로써 어떤 순간에도 수정이 가능하다 (const 함수 내에서도)
public:
	CTextBook(char* text) : mpText(text) {};
	/* 
	const 오버로딩을 위해서 코드의 중복이 발생
	const char& operator[](std::size_t position) const // 상수 객체에 대한 [] 연산자
	{
		// 경계 검사
		// 접근 데이터 로깅
		// 자료 무결성 검증
		return mpText[position];
	};
	char& operator[](std::size_t position) // 상수 객체에 대한 [] 연산자
	{
		// 경계 검사
		// 접근 데이터 로깅
		// 자료 무결성 검증
		return mpText[position];
	};
	*/
	// 코드의 중복을 제거하기 위해 const_cast를 사용하여 const를 제거 후 const CTextBook& 타입으로 캐스팅
	const char& operator[](std::size_t position) const // 상수 객체에 대한 [] 연산자
	{
		// 경계 검사
		// 접근 데이터 로깅
		// 자료 무결성 검증
		return 
			const_cast<char&>( // const_cast를 사용하여 const를 제거
				static_cast<const CTextBook&> // *this 타입에 const를 추가
				(*this)[position] // const CTextBook& 타입으로 캐스팅
			);
	};
	friend std::ostream& operator<<(std::ostream& os, const CTextBook& rhs)
	{
		os << rhs.mpText;
		return os;
	}
	std::size_t GetLength() const
	{
		if (!mLengthIsValid)
		{
			mTextLength = std::strlen(mpText);
			mLengthIsValid = true;
		}
		return mTextLength;
	}
};

int	main(void)
{
	char greeting[] = "Hello";
	const CTextBook ctb(greeting); // 상수 객체를 선언

	char* pc = &ctb[0];

	*pc = 'J';

	std::cout << ctb << std::endl;
	return 0;
}
