#include <stdio.h>

void Swap(int *a, int *b)
{
	int temp; 

	temp = *b;
	*b = *a;
	*a = temp;
}

int Partition(int A[], int l, int h)
{
	int pivot = A[l];
	int i = l;
	int j = h;
	do
	{
		do
		{
			i++;
		} while (A[i] <= pivot);
		do
		{
			j--;
		} while (A[j] > pivot);
		//do { i++; } while (i < h && A[i] < pivot); 
		//do { j--; } while (j >= l && A[j] > pivot);
		
		if (i < j)
			Swap(&A[i], &A[j]);
		
	} while (j > i);
	Swap(&A[l], &A[j]);
	return (j);
}

void QuickSort(int A[], int l, int h)
{
	if (l < h)
	{
		int mid = Partition(A, l, h);
		QuickSort(A, l, mid);
		QuickSort(A, mid + 1, h);
	}
}

int main()
{
	int A[11] = {2, 11, 6, 7, 8, 10, 9, 5, 14, 4, 17, __INT_MAX__};
	QuickSort(A, 0, 11);
	for (size_t i = 0; i < 11; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}