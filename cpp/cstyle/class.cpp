#include <stdio.h>
#include <string.h>

typedef struct s_human t_human;

struct s_human
{
	char name[32];
	int age;
	void (*PrintInfo)(t_human*);
};

// Public member function
void	PrintInfo(t_human* human)
{
	printf("name: %s, age: %d\n", human->name, human->age);
}

// Constructor
void	InitHuman(t_human* human, const char* name, const int age)
{
	strcpy(human->name, name);
	human->age = age;
	human->PrintInfo = PrintInfo;
}

int	main(void)
{
	t_human seunan;
	InitHuman(&seunan, "seunan", 24);
	seunan.PrintInfo(&seunan); // 멤버 함수를 호출할 때 본인의 주솟값을 인자로 넘긴다? => this 포인터
	return 0;
}
