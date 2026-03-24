#include <stdio.h>

void ShellSort(int A[], int n)
{
	int gap, i , j, temp;
	for (gap = n/ 2; gap >= 1 ; gap /= 2)
	{
		for ( i = gap ; i < n; i++)
		{
			temp = A[i];
			j = i - gap;
			while (j >= 0 && A[j] > temp)
			{
				A[j + gap] = A[j];
				//printf("gap: %d  j: %d ",gap, j);
				j = j - gap;
				//printf(" j: %d\n", j);
			}
			A[j + gap] = temp;	
		}
		
	}
	
}

int main()
{
	int A[11] = {2, 10, 9, 4, 5, 6, 8, 7, 3, 14, 11};
	ShellSort(A, 11);
	for (int i = 0; i < 11; i++)
	{
		printf("%d ", A[i]);

	}
	printf("\n");
}