#include "../include/link_list.h"

void	delete_dup(struct Node **head)
{
	//struct Node *first = *head;
	struct Node *outer = *head;
	
	while (outer != NULL)
	{
		struct Node *tail = outer;
		struct Node *inner = outer->next;
		while (inner != NULL)
		{
			if (outer->data == inner->data)
			{

				tail->next = inner->next;
				struct Node *to_delete = inner;
				inner = inner->next;

				free(to_delete);				
			}
			else
			{

				tail = inner;
				inner = inner->next;
			}
		}
		outer = outer->next;
	}
}

void delete_dup_sorted(struct Node **head)
{
	struct Node *tail = *head;
	struct Node *p = (*head)->next;
	while (p != NULL)
	{
		if (tail->data != p->data)
		{
			tail = p->next;
			p = p->next;
		}
		else
		{
			tail = p->next;
			free(p);
			p = tail->next;
		}
	}
	
}