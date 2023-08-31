#include <stdio.h>

__declspec(naked) void TestFunc(int nParam)
{
	__asm
	{
		push        ebp
		mov         ebp, esp
		sub         esp, 10h
	}

	int nData;
	nData = 10;
	puts("TestFunc() - called");

	__asm
	{
		mov         esp, ebp
		pop         ebp
		ret
	}
}

int main(void)
{
	int nData = 5;
	TestFunc(10);
	puts("End of main()");
}