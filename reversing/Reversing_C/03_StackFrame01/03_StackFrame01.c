#include <stdio.h>

void TestFunc(int nParam)
{
	int nData = 10;
	puts("TestFunc() - called");
}

int main(void)
{
	TestFunc(10);
	__asm
	{
		push        0Ah
		call        TestFunc
		add         esp, 4
	}
}