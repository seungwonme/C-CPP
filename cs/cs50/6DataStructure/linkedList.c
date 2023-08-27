#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
} 
node;

int main(void)
{
	node *n = malloc(sizeof(node));
	// (*n).number = 2; 아래의 코드와 같다.
	if (n != NULL)
	{
	n->number = 2;
	n->next = NULL;
	}
	return 0;
}
