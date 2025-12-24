#include <iostream>

void merge(int arr1[], int size1, int arr2[], int size2)
{
	std::cout << "\033[31;1m size arr1: " << size1 << "\033[0m" << std::endl;
	int i = 0;
	int j = 0;
	int ii = 0;
	int arr[size1 + size2];
	while (i < size1 && j < size2)
	{
		if (arr1[i] < arr2[j])
		{
			arr[ii++] = arr1[i];
			i++;
		}
		else if (arr1[i] > arr2[j])
		{
			arr[ii++] = arr2[j];
			j++;
		}
	}
	if (i < size1)
		arr[ii] = arr1[i];
	if (j < size2)
		arr[ii] = arr2[j];
	for (size_t i = 0; i < size1 + size2; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
}

void merge_sort(int arr[], int start, int end)
{
	int mid = (end + start) / 2;
	merge_sort(arr, start, mid + 1);
	merge_sort(arr, mid, end);
	//merge()
}

int main()
{
	int arr1[] = {0, 1, 3};
	int arr2[] = {-1, 2, 4};

	merge(arr1, 3, arr2, 3);
}