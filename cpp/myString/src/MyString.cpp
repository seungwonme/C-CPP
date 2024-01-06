#include <iostream>
#include "MyString.hpp"

static size_t MyStrlen(const char* s);

/* Constructor */

MyString::MyString(void)
{
	mStringContent = new char[1];
	mStringContent[0] = '\0';
	mMemoryCapacity = 1;
	mStringLength = 1;
}
MyString::MyString(char c)
{
	mStringContent = new char[1];
	mStringContent[0] = c;
	mMemoryCapacity = 1;
	mStringLength = 1;
}
MyString::MyString(const char* str)
{
	mStringLength = MyStrlen(str);
	mStringContent = new char[mStringLength];
	mMemoryCapacity = mStringLength;

	for (size_t i = 0; i < mStringLength; i++)
		mStringContent[i] = str[i];
}
// Copy Constructor
MyString::MyString(const MyString& str)
{
	mStringLength = str.mStringLength;
	mStringContent = new char[mStringLength];
	mMemoryCapacity = mStringLength;

	for (size_t i = 0; i < mStringLength; i++)
		mStringContent[i] = str.mStringContent[i];
}

/* Destructor */

MyString::~MyString()
{
	delete[] mStringContent;
}

/* Assignment operator */

void MyString::operator=(const MyString& str)
{
	this->SetContent(str);
}

/* Methods */
void MyString::SetContent(const MyString& str)
{
	if (str.mStringLength > mMemoryCapacity)
	{
		delete[] mStringContent;
		mStringContent = new char[str.mStringLength];
		mMemoryCapacity = mStringLength;
	}
	mStringLength = str.mStringLength;
	for (size_t i = 0; i < mStringLength; i++)
		mStringContent[i] = str.mStringContent[i];
}
void MyString::SetContent(const char* str)
{
	size_t newLen = MyStrlen(str);

	if (newLen > mMemoryCapacity)
	{
		delete[] mStringContent;
		mStringContent = new char[newLen];
		mMemoryCapacity = mStringLength;
	}
	mStringLength = newLen;
	for (size_t i = 0; i < mStringLength; i++)
		mStringContent[i] = str[i];
}
const char* MyString::GetContent(void) const
{
	return mStringContent;
}
size_t MyString::GetLength(void) const
{
	return mStringLength;
}
size_t MyString::GetCapacity(void) const
{
	return mMemoryCapacity;
}
void MyString::Print(void) const
{
	for (size_t i = 0; i < mStringLength; i++)
		std::cout << mStringContent[i];
}
void MyString::Println(void) const
{
	for (size_t i = 0; i < mStringLength; i++)
		std::cout << mStringContent[i];
	std::cout << std::endl;
}
// '=' 과 동일한 역할의 함수
const MyString& MyString::Assign(const MyString& str)
{
	this->SetContent(str);
	return *this;
}
const MyString& MyString::Assign(const char* str)
{
	this->SetContent(str);
	return *this;
}
// 미리 메모리를 할당하는 함수
void MyString::Reserve(size_t size)
{
	size_t i;
	char* newContent;

	newContent = new char[size];
	if (mMemoryCapacity > 0)
	{
		for (i = 0; i < mStringLength && i < size; i++)
			newContent[i] = mStringContent[i];
		delete[] mStringContent;
		mStringContent = newContent;
		mStringLength = i;
	}
	mMemoryCapacity = size;
}
// 해당 인덱스의 문자를 반환하는 함수
char MyString::At(size_t i) const
{
	if (i >= mStringLength)
		return '\0';
	else
		return mStringContent[i];
}
MyString& MyString::Insert(size_t loc, const MyString& str)
{
	char* newContent = mStringContent;
	size_t newLen = mStringLength + str.mStringLength;
	bool bRealloc = newLen > mMemoryCapacity;

	if (loc > mStringLength)
	{
		loc = mStringLength;
	}
	if (bRealloc)
	{
		newContent = new char[newLen];
		mMemoryCapacity = newLen;
	}
	for (size_t i = 0; i < loc; i++)
	{
		newContent[i] = mStringContent[i];
	}
	for (size_t i = newLen - 1; i >= loc + str.mStringLength; i--)
	{
		newContent[i] = mStringContent[i - str.mStringLength];
	}
	for (size_t i = 0; i < str.mStringLength; i++)
	{
		newContent[loc + i] = str.mStringContent[i];
	}

	if (bRealloc)
	{
		delete[] mStringContent;
		mStringContent = newContent;
	}
	mStringLength = newLen;

	return *this;
}
MyString& MyString::Insert(size_t loc, const char* str)
{
	char* newContent = mStringContent;
	size_t insertLen = MyStrlen(str);
	size_t newLen = mStringLength + insertLen;
	bool bRealloc = newLen > mMemoryCapacity;

	if (loc > mStringLength)
	{
		loc = mStringLength;
	}
	if (bRealloc)
	{
		newContent = new char[newLen];
		mMemoryCapacity = newLen;
	}
	for (size_t i = 0; i < loc; i++)
	{
		newContent[i] = mStringContent[i];
	}
	for (size_t i = newLen - 1; i >= loc + insertLen; i--)
	{
		newContent[i] = mStringContent[i - insertLen];
	}
	for (size_t i = 0; i < insertLen; i++)
	{
		newContent[loc + i] = str[i];
	}

	if (bRealloc)
	{
		delete[] mStringContent;
		mStringContent = newContent;
	}
	mStringLength = newLen;

	return *this;
}
MyString& MyString::Insert(size_t loc, char c)
{
	char* newContent = mStringContent;
	size_t newLen = mStringLength + 1;
	bool bRealloc = newLen > mMemoryCapacity;

	if (loc > mStringLength)
	{
		loc = mStringLength;
	}
	if (bRealloc)
	{
		newContent = new char[newLen];
		mMemoryCapacity = newLen;
	}
	for (size_t i = 0; i < loc; i++)
	{
		newContent[i] = mStringContent[i];
	}
	for (size_t i = newLen - 1; i >= loc + 1; i--)
	{
		newContent[i] = mStringContent[i - 1];
	}
	newContent[loc] = c;

	if (bRealloc)
	{
		delete[] mStringContent;
		mStringContent = newContent;
	}
	mStringLength = newLen;

	return *this;
}

/* Static functions */

static size_t MyStrlen(const char* s)
{
	size_t len;

	len = 0;
	while (s[len])
		++len;
	return len;
}