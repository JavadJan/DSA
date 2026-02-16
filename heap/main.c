#include <stdio.h>

void Insert(int A[], int n)
{
	int i = n; // from right to left, 
	int temp = A[n]; // keep the element wants to come Heap Zone
	while (i > 1 && temp > A[i /2])
	{
		A[i] = A[i/2]; /* swap(parent, child) */
		i = i/2; /* backward to iterate */
	}
	A[i] = temp;//
}

/* DELETION */
// in deletion we take the largest from heap, or in other hand we take the root and extract from heap
// we can at the end of list in-place
int Delete(int A[], int n)
{
	int i; // take first element
	int left_child; // 
	int bring_first_to_last = A[1];
	int bring_last = A[n];
	A[1] = bring_last;
	A[n] = bring_first_to_last;

	i = 1;
	left_child = 2 * i;
	int temp;
	while (left_child <= n - 1)
	{
		if (left_child + 1 <= n - 1 && A[left_child + 1] > A[left_child]) // which child is > ?
			left_child = left_child + 1;
		if (A[i] < A[left_child])
		{
			// if parent < child
			temp = A[i];
			A[i] = A[left_child];
			A[left_child] = temp;

			i = left_child;
			left_child = 2 * i;
		}
		else
			break;
	}
	return bring_first_to_last;
}

int main()
{
	int H[8] = {0, 1, 10, 11, 5, 6, 7, 8};
	// 1 is heap, then add 10 into heap => 1, 10 -> 10 , 1
	// i== 3 add 11 into heap
	// next i == 4; add 5 into heap 
	for (size_t i = 2; i < 8; i++)
	{
		Insert(H, i);
	}
	
	for (size_t i = 1; i < 8; i++)
	{
		printf("%d, ", H[i]);
	}
	printf("\n");
	
	// for deletion we give last index from heap
	for (size_t i = 7; i > 1; i--)
	{
		Delete(H, i);
	}


	printf("sorted heap: \n");
	for (size_t i = 1; i < 8; i++)
	{
		printf("%d, ", H[i]);
	}
	printf("\n");
}

/* KEY POINTS:  */
// 1. Heapify
// 2. Deletion
// 3. Creation
// 4. Prioriy Q with heap, because insertion is O(Log n) and deletion is O(log n)