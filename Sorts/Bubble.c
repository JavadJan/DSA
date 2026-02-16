#include "stdio.h"

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(int A[], size_t n)
{
	if (n < 2)
		return ;
	for (size_t i = 0; i < n- 1; i++)
	{
		int flag = 0;
		for (size_t j = 0; j < n - 1- i; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("List has already sorted\n");
			break;
		}
	}
	
}

int main()
{
	int A[12] = {10, 11, 9, 8, 6, 7, 3, 4, 5, 14, 2, 1};
	BubbleSort(A, 12);
	for (size_t i = 0; i < 12; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}