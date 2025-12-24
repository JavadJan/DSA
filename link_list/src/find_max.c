#include "../include/link_list.h"

struct Node *max(struct Node *p)
{
	struct Node* max = p;
	while (p)
	{
		if (p->data > max->data)
			max = p;
		p = p->next;
	}
	return (max);
}

struct Node *rmax(struct Node *p)
{
	struct Node *x = p;
 	if (p == NULL || p->next == NULL)
        return p;
	else{
		x = rmax(p->next);
		if (p->data > x->data)
			return (p);
		else
			return x;
	}
}