#include "../include/link_list.h"
struct Node *merge_list(struct Node *first, struct Node *second)
{
	struct Node *third = NULL;
	struct Node *last = NULL;
	/* check boundery */
	if (first == NULL)
		return (second);
	if (second == NULL)
		return (first);

	/* first step; init third and last */
	//printf("first: ");
	//display(first);
	//printf("second: ");
	//display(second);

	if (first->data < second->data)
	{
		third = last = first;
		first = first->next;
		last->next = NULL;
	}
	else
	{
		third = last = second;
		//last->next->data++;
		printf("last->next: %p, %d\n", last->next, last->next->data);
		printf("second->next: %p, %d\n", second->next, second->next->data);
		second = second->next;
		last->next = NULL;
	}
	//printf("third: ");
	//display(third);
	//printf("first: ");
	//display(first);
	//printf("second: ");
	//display(second);

	//int i = 0;
	while (second != NULL && first != NULL)
	{
		if (first->data < second->data)
		{
			last->next = first; // before it last->next == NULL
			last = first;
			first = first->next;
			last->next = NULL;
		}
		else
		{
			last->next = second;
			last = second; // come one Node forward
			second = second->next;
			last->next = NULL;
		}
		//printf("third: %d", i);
		//display(third);
	}
	if (first != NULL)
		last->next = first;
	else
		last->next = second;
	return (third);
}