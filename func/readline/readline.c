#include <readline/readline.h> // readline
#include <readline/history.h> // add_history
#include <stdio.h> // printf
#include <stdlib.h> // free

int	main(void)
{
	char	*str; // readline함수의 리턴값을 저장할 포인터

	while (1)
	{
		/* readline함수가 호출되면 인자(prompt : )를 터미널에 출력하고 저장할 라인을 입력받는다 */
		str = readline("minishell> "); /* read함수는 저장한 문자열의 메모리주소를 반환한다 */
		printf("%s\n", str);     /* 주소안에 문자열을 출력해보자 */
		add_history(str);
		/* 라인은 힙메모리에 저장되기때문에 다 사용한 메모리는 할당을 해제해줘야한다 */
		free(str);
	}
	/* 함수종료 */
	return (0);
}
