#include "../include/link_list.h"

void insert(struct Node **head, int index, int value)
{
	// the index should not be out of the bound
	struct Node *temp = *head; 
	// this helper is nessassry because the original should not change
	int count = count_recursively(*head); // dar in address boro
	if (index < 0 || index > count)
		return ;
	// create node for value
	struct Node *new_node = create_new_node(value);
	if (!new_node)
		return ;
	// travers until index
	if (index == 0 || *head == NULL)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
	
}

void insert_in_sorted(struct Node **head, struct Node *new)
{
	struct Node *current = *head;
	struct Node *tail = NULL;
	if (*head == NULL)
    {
        new->next = NULL;
        *head = new;
        return;
    }
	if (new->data < (*head)->data)
	{
		new->next = (*head);
		(*head) = new;
	}
	else
	{
		while (current && current->data < new->data)	
		{
			tail = current;
			current = current->next;
		}
		tail->next = new;
		new->next = current;
	}
}