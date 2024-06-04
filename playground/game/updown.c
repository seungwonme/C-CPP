#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char *av[])
{
	srand(time(NULL));

	int	cnt = 1, min = 1, max = 100, user;

	if (ac == 2)
		max = atoi(av[1]);
	if (ac == 3)
	{
		min = atoi(av[1]);
		max = atoi(av[2]);
	}

	int answer = rand() % max + min;

	while (cnt <= 20)
	{
		printf("%d ~ %d\n", min, max);
		scanf("%d", &user);
        if (user > max)
        {
            printf("%d보다 작습니다.\n", user);
        }
		else if (answer > user)
		{
			min = user + 1;
			printf("%d보다 큽니다.\n", user);
		}
		else if (answer < user)
		{
			max = user - 1;
			printf("%d보다 작습니다.\n", user);
		}
		else
		{
			printf("성공 !\n%d번만에 맞추셨어요.\n", cnt);
			return (0);
		}
		++cnt;
	}
	printf("실패 !\n");
	return (0);
}
