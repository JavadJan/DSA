#include <stdlib.h>
#include <stdio.h>

int findMax(int A[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}
	return max;
}
void countSort(int A[], int n)
{
	int max = findMax(A, n);
	int C[max + 1];
	for (int i = 0; i <= max; i++)
	{
		C[i] = 0;
	}
	
	for (int j = 0; j < n; j++)
	{
		C[A[j]]++;
	}

	int i = 0;
	int j = 0;
	while (i <= max)
	{
		if (C[i] > 0)
		{
			A[j++] = i;
			C[i]--;
		}
		else
			i++;
	}
	
	

}

int main()
{
	int A[11] = {10, 2, 9, 11, 14, 7, 8, 6, 3, 5, 4};
	countSort(A, 11);
	for(int i = 0; i < 11; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}