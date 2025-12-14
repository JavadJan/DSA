#include "../include/link_list.h"

struct Node *create_new_node(int data)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	if (!node)
		return (NULL);
	
	node->data = data;
	node->next = NULL;
	return (node);
}