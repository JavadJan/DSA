#include <iostream>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1; // this one should init with low -1, because every time the lowest has being changing
	for (int j = low; j < high; j++) 
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1); // return pivot index in updated array
}

void quick_sort(int arr[], int low , int high)
{
	if (low < high)
	{
		int p = partition(arr, low, high);
		quick_sort(arr, low, p - 1);
		quick_sort(arr, p + 1, high);
	}
}

int main()
{
	int arr[] = {0, -1, 5, 4, 8, 6, 10, 7, 11, 14, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
	return 0;
}