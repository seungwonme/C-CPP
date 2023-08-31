#include <Windows.h>

__declspec(naked) void main()
{
	char buf[5];
	buf[0] = 'c';
	buf[1] = 'a';
	buf[2] = 'l';
	buf[3] = 'c';
	buf[4] = '\0';
	WinExec(buf, 1);
	exit(1);
}