#include <stdio.h>

void Swap(int *j, int *k)
{
	int temp;
	temp = *j;
	*j = *k;
	*k = temp;
}

void SelectionSort(int A[], int n)
{
	int j;
	int k;
	for (int i = 0; i < n - 1; i++)
	{
		j = i;
		k = j;
		while (j < n)
		{
			if(A[j] < A[k])
				k = j;
			j++;
		}
		Swap(&A[i], &A[k]);
	}
	
}
int main()
{
	int A[11] = {2, 11, 6, 7, 8, 10, 9, 5, 14, 4, 17};
	SelectionSort(A, 11);
	for (size_t i = 0; i < 11; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}