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
		printf("스레드에서 출력하는 메시지: %s\n", szBuffer);
		putchar(szBuffer[g_nSize]);
		putchar('\n');

		if (strcmp(szBuffer, "exit") == 0)
			break;
	}

	puts("스레드 종료");
//	_endthread();
}

int main(void)
{
	_beginthread(ThreadFunction, 0, NULL);

	while (strcmp(g_szData, "exit") != 0)
	{
		printf("문자열을 입력하세요: ");
		gets(g_szData);
	}

	Sleep(1200);
	puts("응용 프로그램 종료");
	return 0;
}

//문제
//1. 긴 문자열을 입력하면 이 프로그램은 비정상 종료된다.
//   그렇다면 대략 몇 글자 이상인가?
//2. 프로그램이 죽은 직접적인 원인은 무엇인가?
//3. 2번에서 언급한 직접적인 원인이 발생한 이유는 무엇인가?