#include "../include/link_list.h"

int sum(struct Node *p)
{
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return (sum);
}

int rsum(struct Node *p)
{
	if (p == NULL)
		return 0;
	else
		return rsum(p->next) + p->data;
}