#pragma once

class CUserData
{
	friend class CMyList;

public:
	CUserData(void);
	~CUserData(void);

	const char* getName(void) const { return szName; }
	const char*	getPhone(void) const { return szPhone; }
	const CUserData* getNext(void) const { return pNext; }

	static int getUserDataCounter(void) { return nUserDataCounter; }

protected:
	char szName[32];   // �̸�
	char szPhone[32];  // ��ȭ��ȣ

	CUserData *pNext;

	static int nUserDataCounter;
};