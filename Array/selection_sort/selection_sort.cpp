//#ifndef SELECTION_SORT_HPP
//#define SELCTION_SORT_HPP

#include <cstddef>
#include <iostream>

//#endif // SELECTION_SORT_HPP

void selection_sort(int arr[], int len)
{
	int i = 0;
	int j = 0;

	while (i < len)
	{
		int min_idx = i;
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		// Swap arr[i] and arr[min_idx]
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
		i++;
	}
	i = 0;
	while (i < len)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	int arr[] = {1, 3, -1, 0, 5, 10, 6, 8, 7, 11, 14};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	selection_sort(arr, len);
}

/* find the minimum and move that in front of array
	int min = arr[0];
	for ( i < len)
	{
		int min_index = i;
		for ( j = i + 1 < len) #every time the inner loop becomes shorter
			if (n < min)
				min = n;
		arr[i] = min;
		i++;
	}
*/