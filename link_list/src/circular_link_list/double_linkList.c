#include <stdio.h>
#include <stdlib.h>

typedef struct link_list
{
	struct link_list *prev;
	int data;
	struct link_list *next;
} t_lst ;

t_lst *head = NULL;

t_lst *create_new_node(int data)
{
	t_lst *new_node = (t_lst *)malloc(sizeof(t_lst));
	if (!new_node)
		return NULL;
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}
t_lst *create_list(int A[], int size)
{
	t_lst *head = create_new_node(A[0]);
	if (!head)
		return (NULL);
	
	t_lst *p = head;

	for (int i = 1; i < size; i++)
	{
		t_lst *temp = create_new_node(A[i]);
		if (!temp)
		{
			// Free previously allocated nodes
			t_lst *curr = head;
			while (curr)
			{
				t_lst *next = curr->next;
				free(curr);
				curr = next;
			}
			return NULL;
		}
		t_lst *prev = p;
		p->next = temp;
		p = p->next;
		p->prev = prev;
	}
	return head;
}

int	list_len()
{
	t_lst *p = head;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void insert(int pos, int x)
{
	if (pos >list_len() || pos < 0)
		return ;
	t_lst *p;
	if (pos == 0)
	{
		if (head == NULL)
		{
			head = create_new_node(x);
			if (!head)
				return;
		}
		else{
			t_lst *new_node = create_new_node(x);
			if (!new_node)
				return ;

			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}

	}
	else{
		t_lst *new_node = create_new_node(x);
			if (!new_node)
				return ;
			
		p = head;
		for (int i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}
		
		new_node->next = p->next;
		new_node->prev = p;
		p->next = new_node;
		if (new_node->next)
			new_node->next->prev = new_node;
	}
}



void display()
{
	t_lst *p = head;
	t_lst *last = NULL;
	while (p!=NULL)
	{
		printf("%d->", p->data);
		last = p;
		p = p->next;
	}
	printf("\n");
	// display one more time from last to start
	p = last;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->prev;
	}
	printf("\n");
	
}
int main()
{
	int A[] = {10, 7, 8, 6, 9, 11};
	head = create_list(A, 6);
	insert(2, 14);
	display();
}
