#pragma	once
#include <cstddef>

class MyString {
private:
	char* mStringContent;		// 문자열 데이터를 가리키는 포인터
	size_t mStringLength;	// 문자열 길이
	size_t mMemoryCapacity;	// mStringContent에 할당된 메모리
public:
	MyString(void);
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();
	void			operator=(const MyString& str);
	operator const char* () const;
	void			SetContent(const MyString& str);
	void			SetContent(const char* str);
	const char*		GetContent(void) const;
	size_t			GetLength(void) const;
	size_t			GetCapacity(void) const;
	const MyString&	Assign(const MyString& str);
	const MyString&	Assign(const char* str);
	void			Reserve(size_t size);
	char			At(size_t i) const;
	MyString&		Insert(size_t loc, const MyString& str);
	MyString&		Insert(size_t loc, const char* str);
	MyString&		Insert(size_t loc, char c);
};
