#include "MyString.hpp"

size_t MyStrlen(const char* s)
{
	size_t len;

	len = 0;
	while (s[len])
		++len;
	return len;
}

MyString::MyString(char c)
{
	mStringContent = new char[1];
	mStringContent[0] = c;
	mMemoryCapacity = 1;
	mStringLength = 1;
}
// 문자열로 부터 생성
MyString::MyString(const char* str)
{
	mStringLength = MyStrlen(str);
	mStringContent = new char[mStringLength];
	mMemoryCapacity = mStringLength;

	for (size_t i = 0; i < mStringLength; i++)
		mStringContent[i] = str[i];
}
// 복사 생성자
MyString::MyString(const MyString& str)
{
	mStringLength = str.mStringLength;
	mStringContent = new char[mStringLength];
	mMemoryCapacity = mStringLength;

	for (size_t i = 0; i < mStringLength; i++)
		mStringContent[i] = str.mStringContent[i];
}
MyString::~MyString()
{
	delete[] mStringContent;
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
MyString& MyString::Assign(const MyString& str)
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
	return *this;
}
MyString& MyString::Assign(const char* str)
{
	size_t newLen;

	newLen = MyStrlen(str);
	if (newLen > mMemoryCapacity)
	{
		delete[] mStringContent;
		mStringContent = new char[newLen];
		mMemoryCapacity = newLen;
	}
	mStringLength = newLen;
	for (size_t i = 0; i < mStringLength; i++)
		mStringContent[i] = str[i];
	return *this;
}
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
char MyString::At(size_t i)
{
	if (i >= mStringLength)
		return '\0';
	else
		return mStringContent[i];
}
MyString& MyString::Insert(size_t loc, const MyString& str)
{
	char* newContent;
	size_t newLen;
	size_t i;

	newLen = mStringLength + str.mStringLength;
	newContent = new char[mStringLength];
	for (i = 0; i < loc && i < mStringLength; i++)
		newContent[i] = mStringContent[i];
	for (size_t j = 0; j < str.mStringLength; j++)
	{
		newContent[i] = str.mStringContent[j];
		++i;
	}
	for (size_t j = loc; i < newLen; i++)
	{
		newContent[i] = mStringContent[j];
		++j;
	}
	delete[] mStringContent;
	mStringContent = newContent;
	mStringLength = newLen;
	return *this;
}
MyString& MyString::Insert(size_t loc, const char* str)
{
	char* newContent;
	size_t newLen;
	size_t i;

	newLen = mStringLength + MyStrlen(str);
	newContent = new char[mStringLength];
	for (i = 0; i < loc && i < mStringLength; i++)
		newContent[i] = mStringContent[i];
	for (size_t j = 0; j < MyStrlen(str); j++)
	{
		newContent[i] = str[j];
		++i;
	}
	for (size_t j = loc; i < newLen; i++)
	{
		newContent[i] = mStringContent[j];
		++j;
	}
	delete[] mStringContent;
	mStringContent = newContent;
	mStringLength = newLen;
	return *this;
}
MyString& MyString::Insert(size_t loc, char c)
{
	char* newContent;
	size_t newLen;
	size_t i;

	newLen = mStringLength + 1;
	newContent = new char[mStringLength];
	for (i = 0; i < loc && i < mStringLength; i++)
		newContent[i] = mStringContent[i];
	newContent[i] = c;
	++i;
	for (size_t j = loc; i < newLen; i++)
	{
		newContent[i] = mStringContent[j];
		++j;
	}
	delete[] mStringContent;
	mStringContent = newContent;
	mStringLength = newLen;
	return *this;
}
