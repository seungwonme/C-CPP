#include <iostream>

class MyString {
private:
	char* mStringContent;		// 문자열 데이터를 가리키는 포인터
	size_t mStringLength;		// 문자열 길이
	size_t mMemoryCapacity;	// mStringContent에 할당된 메모리
public:
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	~MyString();

	size_t		GetLength(void) const;
	size_t		GetCapacity(void) const;
	void			Print(void) const;
	void			Println(void) const;
	// '=' 과 동일한 역할의 함수
	MyString&	Assign(const MyString& str);
	MyString&	Assign(const char* str);
	// 미리 메모리를 할당하는 함수
	void			Reserve(size_t size);
	// 해당 인덱스의 문자를 반환하는 함수
	char			At(size_t i);
	MyString&	Insert(size_t loc, const MyString& str);
	MyString&	Insert(size_t loc, const char* str);
	MyString&	Insert(size_t loc, char c);
};
