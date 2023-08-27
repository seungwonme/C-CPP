#include <stdio.h>
#include <string.h>
#include <ctype.h> // toupper 함수 호출

int main(void)
{
	char str[32];
	printf("before : ");
	scanf("%s",str);
	printf("after : ");
	/* for (int i = 0, n = strlen(str); i < n; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z') 
		{
			printf("%c",(int) str[i] - 32);
		}
		else
		{
			printf("%c",str[i]);
		}
	}
	printf("\n"); */
	for (int i = 0, n = strlen(str); i < n; i++)
	{
		printf("%c",toupper(str[i]));
	}
	printf("\n");
	return 0; 
}
