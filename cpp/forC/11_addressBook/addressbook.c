#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////////////////////////////
void releaseList();

/////////////////////////////////////////////////////////////////////////
typedef struct _USERDATA
{
	char szName[32];	  // �̸�
	char szPhone[32];	  // ��ȭ��ȣ

	struct _USERDATA* pNext;
} USERDATA;

// ���� ��� ��� ���� �� ����
USERDATA g_Head = { 0 };


/////////////////////////////////////////////////////////////////////////
// ����Ʈ���� �̸����� Ư�� ��带 �˻��ϴ� �Լ�
USERDATA* findNode(char* pszName)
{
	USERDATA* pTmp = g_Head.pNext;
	while (pTmp != NULL) {
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		// ���� ���� �̵�
		pTmp = pTmp->pNext;
	}

	// ��ġ�ϴ� �����͸� ã�� ���� ���
	return NULL;
}

/////////////////////////////////////////////////////////////////////////
int addNewNode(char* pszName, char* pszPhone)
{
	USERDATA* pNewUser = NULL;

	// ���� �̸��� �̹� �����ϴ��� Ȯ���Ѵ�.
	if (findNode(pszName) != NULL)
		return 0;

	// �޸𸮸� Ȯ���Ѵ�.
	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewUser, 0, sizeof(USERDATA));

	// �޸𸮿� ���� �����Ѵ�.
	sprintf_s(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
	sprintf_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
	pNewUser->pNext = NULL;

	// ���� ��� �ٷ� �ڿ� ���δ�. ���� ���� �ֱٿ�
	// �߰��� �����Ͱ� ���� ���ʿ� �´�. 
	pNewUser->pNext = g_Head.pNext;
	g_Head.pNext = pNewUser;

	return 1;
}

/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� ����Ʈ�� �߰��ϴ� �Լ�
void addUser()
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	printf("Input name : ");
	gets_s(szName, sizeof(szName));
	//flushInputBuffer();

	printf("Input phone number : ");
	gets_s(szPhone, sizeof(szPhone));
	//flushInputBuffer();

	// ������ ����Ʈ�� �߰��Ѵ�.
	addNewNode(szName, szPhone);
}

/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϴ� �Լ�
void searchUser()
{
	char szName[32] = { 0 };
	USERDATA* pNode = NULL;

	printf("Input name : ");
	gets_s(szName, sizeof(szName));

	pNode = findNode(szName);
	if (pNode != NULL) {
		printf("[%p] %s\t%s [%p]\n",
			pNode,
			pNode->szName, pNode->szPhone,
			pNode->pNext);
	}

	else {
		puts("ERROR: �����͸� ã�� �� �����ϴ�.");
	}

	_getch();
}

/////////////////////////////////////////////////////////////////////////
// ����Ʈ�� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
void printAll()
{
	USERDATA* pTmp = g_Head.pNext;
	while (pTmp != NULL) {
		printf("[%p] %s\t%s [%p]\n",
			pTmp,
			pTmp->szName, pTmp->szPhone,
			pTmp->pNext);

		pTmp = pTmp->pNext;
	}

	_getch();
}

/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϰ� �����ϴ� �Լ�
int removeNode(char* pszName)
{
	USERDATA* pPrevNode = &g_Head;
	USERDATA* pDelete = NULL;

	while (pPrevNode->pNext != NULL) {
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->szName, pszName) == 0) {
			pPrevNode->pNext = pDelete->pNext;
			free(pDelete);

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �ڷḦ �˻��ϰ� �����ϴ� �Լ�
void removeUser()
{
	char szName[32] = { 0 };

	printf("Input name : ");
	gets_s(szName, sizeof(szName));

	if (removeNode(szName))
		puts("�����Ϸ�.");
	else
		puts("ERROR: ������ �����͸� ã�� �� �����ϴ�.");
	_getch();
}

/////////////////////////////////////////////////////////////////////////
// �޴��� ����ϴ� UI �Լ�
int printUI()
{
	int nInput = 0;

	system("cls");
	printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	scanf_s("%d%*c", &nInput);

	return nInput;
}


/////////////////////////////////////////////////////////////////////////
// ����Ʈ�� ��� �����͸� �����ϴ� �Լ�
void releaseList()
{
	USERDATA* pTmp = g_Head.pNext;
	USERDATA* pDelete = NULL;

	while (pTmp != NULL) {
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		free(pDelete);
	}

	memset(&g_Head, 0, sizeof(USERDATA));
}

/////////////////////////////////////////////////////////////////////////
void main()
{
	int nMenu = 0;

	// ���� �̺�Ʈ �ݺ���
	while ((nMenu = printUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add
			addUser();
			break;

		case 2:		  // Search
			searchUser();
			break;

		case 3:		 // Print all
			printAll();
			break;

		case 4:		  // Remove
			removeUser();
			break;
		}
	}

	releaseList();
}