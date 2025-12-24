#include "../include/link_list.h"

char *check_sorted(struct Node *p)
{
	while (p->next != NULL)
	{
		if (p->next->data < p->data)
			return ("This link_list is not sorted");
		p = p->next;
	}
	return ("This link_list is sorted");
}

bool check_sorted2(struct Node *p)
{
	int min = -32768;
	while (p != NULL)
	{
		if (p->data < min)
			return (false);
		min = p->data;
		p = p->next;
	}
	return (true);
}

bool rcheck_sorted(struct Node *p)
{
	if (p->next == NULL || p == NULL)
		return (true);
	if (p->next->data < p->data)
		return (false);
	return (rcheck_sorted(p->next));
}