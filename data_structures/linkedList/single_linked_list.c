#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
	char		*content;
	struct list	*next;
} list;

list	*find_last(list *node) // 리프 노드 반환
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

list	*create_node(list *node) // 현재 노드에서 노드 추가
{
	if (!node)
		return (0);
	node->next = (list *)malloc(sizeof(node) * 1);
	if (!node->next)
		return (0);
	node = node->next;
	node->next = NULL;
	return (node->next);
}

void	print_node(list *head) // 헤드부터 모든 노드의 콘텐츠값 출력
{
	if (!head)
		return ;
	while (head)
	{
		printf("%s\n", head->content);
		head = head->next;
	}
}

void	fill_content(list *node, char *text) // 노드의 콘텐츠값 추가
{
	int	len;

	len = strlen(text);
	node->content = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		node->content[i] = text[i];
	node->content[len] = '\0';
}

int	main(void)
{
	list	**head;
	head = (list **)malloc(sizeof(list *) * 1);
	fill_content(*head, "안녕 나는 헤드얌");
	(*head)->next = create_node(*head);
	fill_content(find_last(*head), "안녕 나는 2번째 노드얌");
	print_node(*head);
	return (0);
}
