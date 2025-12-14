#include "../include/link_list.h"

void	display(struct Node *head)
{
	struct Node *temp = head;
	int step = 0;
	while (temp != NULL && step < 30)
	{
		printf("%d",temp->data);
		if (temp->next != NULL)
			printf("->");
		temp = temp->next;
		step++;
	}
	printf("\n");
	if (step == 30)
		printf("⚠️ Cycle detected\n");
}

void	circular_display(struct Node *head)
{
	struct Node *p = head;
	do
	{
		printf("%d->", p->data);
		p = p->next;
	} while (p!= head);
	printf("\n");
}


void	r_circular_display(struct Node *head)
{
	static int flag = 0;
	if (p!= head || flag == 0)
	{
		flag = 1;
		printf("%d->",p->data);
		circular_display(p->next);
	}
	flag = 0;
}