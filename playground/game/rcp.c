#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// 가위 < 바위 < 보
// 한글 3byte

int main(void)
{
	srand(time(NULL));

	char	bot[3][7] = {"가위", "바위", "보"}, user[7] = { 0 }, *rcp;

	while (1)
	{
		system("clear");
		printf("가위, 바위, 보 중 하나를 내세요.\n");
		scanf("%s", user);
		rcp = bot[(int)rand() % 3];
		if (strcmp(user, rcp) == 0)
			printf("당신은 %s를 냈고 컴퓨터는 %s를 냈습니다.\n비겼습니다.\n", user, rcp);
		else if (strcmp(user, rcp) > 0)
		{
			if (strcmp(user, "보") == 0 && strcmp(rcp, "가위") == 0)
				printf("당신은 %s를 냈고 컴퓨터는 %s를 냈습니다.\n졌습니다.\n", user, rcp);
			else
				printf("당신은 %s를 냈고 컴퓨터는 %s를 냈습니다.\n이겼습니다.\n", user, rcp);
		}
		else
		{
			if (strcmp(user, "가위") == 0 && strcmp(rcp, "보") == 0)
				printf("당신은 %s를 냈고 컴퓨터는 %s를 냈습니다.\n이겼습니다.\n", user, rcp);
			else
				printf("당신은 %s를 냈고 컴퓨터는 %s를 냈습니다.\n졌습니다.\n", user, rcp);
		}
		sleep(2);
	}
	return (0);
}
