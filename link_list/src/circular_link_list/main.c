#include <stdio.h>
#include <stdlib.h>

struct linkList{
	int data;
	struct linkList *next;
} *head;

void create_circyle_link_list(int A[], int size)
{
	struct linkList *t, *last;
	head = (struct linkList *)malloc(sizeof(struct linkList));
	if (!head)
		return;
	
	head->data = A[0];
	head->next = head;
	last = head;
	for (int i = 1; i < size; i++)
	{
		t = (struct linkList *)malloc(sizeof(struct linkList));
		if (!t)
			return;
		t->data = A[i];
		t->next = head;
		last->next = t;
		last = t;
	}
	
}

int	len_list()
{
	if (head == NULL)
		return 0;
	struct linkList *p = head;
	int i = 0;
	do
	{
		i++;
		p = p->next;
	} while (p!=head);
	return i;
}
void insert(int index, int x)
{
	struct linkList *p = head;
	if (index > len_list() || index < 0)
		return;
	struct linkList *new_node = (struct linkList *)malloc(sizeof(struct linkList));
	if (!new_node)
		return;
	new_node->data = x;
	new_node->next = NULL;
	if (index == 0)
	{
		if (head == NULL)
		{
			head = new_node;
			head->next = head;
			return ;
		}

		while (p->next != head)
		{
			p = p->next;
		}
		new_node->next = head;
		p->next = new_node;
		head = new_node;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		new_node->next = p->next->next;
		p->next = new_node;		
	}
}
void display(struct linkList *p)
{
	do
	{
		printf("%d->", p->data);
		p = p->next;
	} while (p != head);
	
}

void free_list(struct linkList *p)
{
    if (p == NULL)
        return;

    struct linkList *tmp = p;
    struct linkList *temp;

    do
    {
        temp = p;
        p = p->next;
        free(temp);
    } while (p != tmp);  // ✅ Stop when we return to head
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
//										#
//			double link list			#
//										#
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

int main()
{
	int A[] = {2, 3, 4, 5, 6};
	create_circyle_link_list(A, 5);
	insert(0, 7);
	display(head);
	free_list(head);
	printf("\n");
}