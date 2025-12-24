#include "../include/link_list.h"

struct Node *search(struct Node *p, int key)
{
	while (p)
	{
		if (p->data == key)
			return (p);
		p = p->next;
	}
	return (NULL);
}

struct Node *Rsearch(struct Node *p, int key)
{

	if (p == NULL)
		return (NULL);
	if (p->data == key)
		return (p);
	return Rsearch(p->next, key);
}

struct Node *improved_search(struct Node **head, int key)
{
	struct Node *tail = NULL;
	struct Node *first = *head;
	//printf("\n\nfirst node: %p\n", first);
	while (first != NULL)
	{
		if (first->data == key)
		{			
			tail->next = first->next;
			//printf("stil first: %p(*head)\n", first);
			first->next = *head;
			
			//printf("p found: %p *p: %d new: %d\n", (*head),(*head)->data, (*head)->next->data);
			*head = (first);
			//printf("first: %p *first: %d\n", first ,first->data);
			return (*head);
		}
		tail = first;
		first = first->next;
	}
	return (NULL);
}