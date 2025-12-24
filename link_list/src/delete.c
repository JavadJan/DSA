#include "../include/link_list.h"
void	delete_first(struct Node **head)
{
	if ((*head)->next == NULL) // just for one element
	{
		free(*head);
		(*head) = NULL;
		return;
	}
	struct Node *temp = *head;
	(*head) = (*head)->next;
	temp->next = NULL;
	free(temp);
}

void delete_at(struct Node **head, int index)
{
	if (index < 1)
		return ;
	if (index == 1)
	{
		delete_first(head);
	}
	struct Node *temp = *head;
	int i = 0;
	while (temp && (i < index - 1))
	{
		i++;
		temp = temp->next;
	}
	if (temp == NULL || temp->next == NULL)
        return; // index out of range
	struct Node *to_delete = temp->next;
	temp->next = temp->next->next;
	int x = to_delete->data; // in case you need the x in another reason
	printf("delete at elem: %d\n", x);
	to_delete->next= NULL;
	free(to_delete);
}

void	delete_at_index_tow(struct Node **head, int index){
	if (index < 1)
		return ;
	if (index == 1)
	{
		delete_first(head);
	}
	struct Node *temp = *head;
	struct Node *tail = NULL;
	int i = 0;
	while (temp && (i < index - 1))
	{
		i++;
		tail = temp;
		temp = temp->next;
	}
	tail->next = temp->next;
	int x = temp->data; // in case you need the x in another reason
	printf("delete elem: %d\n", x);
	free(temp);
	
}

