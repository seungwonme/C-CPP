#pragma	once
#include <cstddef>

class MyString {
private:
	char* mStringContent;		// 문자열 데이터를 가리키는 포인터
	size_t mStringLength;		// 문자열 길이
	size_t mMemoryCapacity;	// mStringContent에 할당된 메모리
public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str); // 복사 생성자
	~MyString();

	size_t			GetLength(void) const;
	size_t			GetCapacity(void) const;
	void			Print(void) const;
	void			Println(void) const;
	// '=' 과 동일한 역할의 함수
	const MyString&	Assign(const MyString& str);
	const MyString&	Assign(const char* str);
	// 미리 메모리를 할당하는 함수
	void			Reserve(size_t size);
	// 해당 인덱스의 문자를 반환하는 함수
	char			At(size_t i) const;
	MyString&		Insert(size_t loc, const MyString& str);
	MyString&		Insert(size_t loc, const char* str);
	MyString&		Insert(size_t loc, char c);
};
