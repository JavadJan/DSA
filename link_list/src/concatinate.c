#include "../include/link_list.h"

void	concatinate(struct Node **lst0, struct Node **lst1)
{
	if (*lst0 == NULL)
	{
		*lst0 = *lst1;
		return ;		
	}
	struct Node *last = last_node(*lst0);
	if (!last)
		return;
	last->next = *lst1;
}