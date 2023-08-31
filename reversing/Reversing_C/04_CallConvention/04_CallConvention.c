#include <stdio.h>

int __cdecl TestFunc1(int a, int b, int c)
{
	puts("TestFunc1() - called");
	return 0;
}

int __stdcall TestFunc2(int a, int b, int c)
{
	puts("TestFunc2() - called");
	return 0;
}

int __fastcall TestFunc3(int a, int b, int c)
{
	puts("TestFunc3() - called");
	return 0;
}

int main(void)
{
	TestFunc1(1, 2, 3);
	TestFunc2(1, 2, 3);
	TestFunc3(1, 2, 3);
}