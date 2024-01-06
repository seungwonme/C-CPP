#pragma once
#include "MyNode.h"

// CMyNode Ŭ������ �Ļ� Ŭ������ ����
class CUserData : public CMyNode
{
public:
	CUserData(void);
	CUserData(const char* pszName, const char* pszPhone);
	~CUserData(void);

	const char* getName(void) const { return szName; }
	const char*	getPhone(void) const { return szPhone; }
	static int getUserDataCounter(void) { return nUserDataCounter; }

protected:
	char szName[32];
	char szPhone[32];

	// pNext ����� �������.
	static int nUserDataCounter;

public:
	// ���� ���� �Լ��� ����
	virtual const char* getKey(void);
	virtual void printNode(void);
};