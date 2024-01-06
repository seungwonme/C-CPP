#pragma once
#include "MyNode.h"
#include "MyIterator.h"

class CMyList
{
public:
	CMyList(CMyNode *pHead);
	~CMyList(void);

protected:
	void releaseList(void);
	CMyNode *m_pHead;

public:
	CMyNode* findNode(const char* pszKey);
	int addNewNode(CMyNode *pNewNode);

	// UI �ڵ�. ����� �ٶ������� �ʴ�.
	// void PrintAll(void);
	int removeNode(const char* pszKey);

	// �����ڸ� �����Ѵ�.
	CMyIterator makeIterator(void);

	// �����Ͱ� �߰��� ������ ȣ��Ǵ� ���� �Լ�
	virtual int onAddNewNode(CMyNode* pNewNode);
};