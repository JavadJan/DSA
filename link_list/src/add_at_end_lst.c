#include "../include/link_list.h"

void add_at_end_lst(struct Node **head, struct Node *node)
{
	if (*head == NULL)
	{
		*head = node;
		printf("cast \033[1;33m%p\033[0m to *head\n", node);
		printf("att address \033[1;31m%p\033[0m stored: \033[1;31m%p\033[0m\n",head, *head);
		return ;
	}
	struct Node *last = last_node(*head);
	last->next = node;
	printf("cast %p to %p\n", node, last->next);
	printf("at address \033[1;33m%p\033[0m stored: \033[1;32m%p\033[0m\n",last->next, node);
	
}