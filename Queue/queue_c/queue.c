#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct	Queue
{
	int	size;
	int	front;
	int	rear;
	int	*Q;
};

int	enqueue(struct Queue *q, int x)
{
	if (q->front == q->size - 1)
	{
		printf("Queue is full\n");
		return (1);
	}
	else
	{
		q->rear++;
		q->Q[q->rear] = x;
	}
	return (0);
}

int	dequeue(struct Queue *q)
{
	int x = -1;
	if (q->front == q->rear)
	{
		printf("Queue is empty\n");
	}
	else
	{

		q->front++;
		x = q->Q[q->front];// front-> |_|_|_|_|_|_| <-rear
		printf("deleted the element %d from Q\n", x);
	}
	return (x);
}

void	display(struct Queue q)
{
	if (q.front == q.rear)
	{
		printf("Queueu is empty, nothing to display\n");
		return ;
	}
	for (size_t i = q.front + 1; i < q.rear + 1; i++)
	{
		printf("%d, ", q.Q[i]);
	}
	printf("\n");
}

int	main(void)
{
	struct Queue q;
	printf("Enter the size of Queue: ");
	scanf("%d", &q.size); // get the size from user

	q.front = q.rear = -1;
	q.Q = (int *)malloc(sizeof(int) * q.size);
	if (!q.Q)
		return (1);

	int x = -1;
	int i = 0;
	while (i < q.size)
	{
		printf("enter the element %d: ", i);
		if (scanf("%d", &x) < 0)
		{
			printf("Faile to read element\n");
			return (2);
		}
		else
		{
			if (x == 100)
			{
				printf("you exited\n");
				display(q);
				exit(1);
			}
			enqueue(&q, x);
		}
		i++;
	}

	display(q);
	
	dequeue(&q);
	display(q);
	// while (q.front != q.rear)
	//{
	//	dequeu
	//}
}