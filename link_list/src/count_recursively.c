#include "../include/link_list.h"

int count_recursively(struct Node *head)
{
	if (head == NULL)
		return (0);
	else
		return 1 + count_recursively(head->next);
}