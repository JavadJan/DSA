#include "../include/link_list.h"

void recursive_display(struct Node *head)
{
	if (head != NULL)
	{
		printf("%d->",head->data); // assending recursive
		recursive_display(head->next);
		//printf("%d->",head->data); // dessending recursive
	}
	printf("\n");
}