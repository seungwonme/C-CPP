#include <Windows.h>
#include <process.h>

char g_szData[12] = { "Empty" };
int g_nSize = 12;

void ThreadFunction(void *pParam)
{
	char szBuffer[12];
	while (1)
	{
		Sleep(1000);
		strcpy(szBuffer, g_szData);
		printf("�����忡�� ����ϴ� �޽���: %s\n", szBuffer);
		putchar(szBuffer[g_nSize]);
		putchar('\n');

		if (strcmp(szBuffer, "exit") == 0)
			break;
	}

	puts("������ ����");
//	_endthread();
}

int main(void)
{
	_beginthread(ThreadFunction, 0, NULL);

	while (strcmp(g_szData, "exit") != 0)
	{
		printf("���ڿ��� �Է��ϼ���: ");
		gets(g_szData);
	}

	Sleep(1200);
	puts("���� ���α׷� ����");
	return 0;
}

//����
//1. �� ���ڿ��� �Է��ϸ� �� ���α׷��� ������ ����ȴ�.
//   �׷��ٸ� �뷫 �� ���� �̻��ΰ�?
//2. ���α׷��� ���� �������� ������ �����ΰ�?
//3. 2������ ����� �������� ������ �߻��� ������ �����ΰ�?