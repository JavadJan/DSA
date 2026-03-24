#include <stdio.h>

void InsertionSort(int A[], size_t n)
{
	int i;
	int j;
	int x;
	for (j = 1; j < n; j++)
	{
		i = j -1;
		x = A[j];
		while (i > -1 && A[i] > x)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = x;
	}
	
}



int main()
{
	int A[12] = {10, 11, 9, 14 , 7, 1, 2, 5, 6, 8, 3, 17};
	InsertionSort(A, 12);
	for (size_t i = 0; i < 12; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	
}