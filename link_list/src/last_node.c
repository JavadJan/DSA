#include "../include/link_list.h"

struct Node *last_node(struct Node *head)
{
	if (head == NULL)
		return (head);
	struct Node *last;
	last = head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}