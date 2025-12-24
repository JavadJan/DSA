#include "../include/link_list.h"

void	reverse_link(struct Node **head)
{
	struct Node *p = *head;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	int A[len];

	p = *head;
	int i = 0;
	while (p != NULL)
	{
		A[i] = p->data;
		i++;
		p = p->next;
	}
	
	i--;
	p = *head;
	while (p != NULL)
	{
		p->data = A[i--];
		p = p->next;
	}
	
}

void	reverse_link_sliding(struct Node **head)
{
	struct Node *r = NULL;
	struct Node *q = NULL;
	struct Node *p = *head;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*head = q;
}