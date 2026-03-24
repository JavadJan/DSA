#include <stdio.h>

/* iterative merge sort */
//void merge(int A[], int l, int mid, int h)
//{
//	int i, j, k;
//	i = l;
//	j = mid + 1;
//	k = 0;
//	int B[h - l + 1];
//	while (i <= mid && j <= h)
//	{
//		if (A[i] <= A[j])
//			B[k++] = A[i++];
//		else
//			B[k++] = A[j++];
//	}
//	while (i <= mid)
//	{
//		B[k++] = A[i++];
//	}
//	while (j <= h)
//	{
//		B[k++] = A[j++];
//	}
	
//	for (int x = 0; x <= h; x++)
//	{
//		A[x] = B[x];
//	}
//}

void merge(int A[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = 0;                 // start B from 0

    int B[h - l + 1];

    while (i <= mid && j <= h)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= mid)
        B[k++] = A[i++];

    while (j <= h)
        B[k++] = A[j++];

    // Copy back correctly
    for (int x = 0; x < k; x++)
        A[l + x] = B[x];
}

void MergeSort(int A[], int n)
{
	int l, mid, h;

	int p;
	for (p = 2; p <= n; p *= 2)
	{
		// [0, 2) | [2, 4) | [4, 6] ... 
		for (int i = 0; i + p-1 < n; i += p)
		{
			l = i;
			h = i + p -1;
			mid  = (h + l) /2;
			merge(A, l, mid, h);
		}
		
	}
	if (p /2 < n)
		merge(A, 0, p /2 - 1, n-1);
}

void RMergeSort(int A[], int l, int h)
{
	int mid;
	if (l < h)
	{
		mid = (h + l) /2;
		RMergeSort(A, l, mid);
		RMergeSort(A, mid+ 1,h);
		merge(A, l, mid, h);
	}
}

int main()
{
	int A[11] = {10, 9, 2, 4, 5, 7, 8, 11, 6, 14, 17};
	MergeSort(A, 11);
	int B[11] = {10, 9, 2, 4, 5, 7, 8, 11, 6, 14, 17};
	for (int i = 0; i < 11; i++)
	{
		printf("%d ", A[i]);
	}
	
	printf("\n");
	RMergeSort(B, 0, 10);
	for (int i = 0; i < 11; i++)
	{
		printf("%d ", B[i]);
	}
	printf("\n");
}