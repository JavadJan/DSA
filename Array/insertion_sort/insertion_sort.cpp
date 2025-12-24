#include <iostream>


void insertion_sort(int arr[], int len)
{
	int i =0;
	int j =0;
	// Standard in-place insertion sort
	for (int i = 1; i < len; i++) //that picks a value to be sorted, it start from 1, because firs does need to be sorted
	{
		int key = arr[i]; // [31, 1, 3, 5,2]
		int j = i - 1; //  i == 1 -> j == 0; i == 2 -> j = 1 
		// Move elements of arr[0..i-1], that are greater than key, to one position ahead
		while (j >= 0 && arr[j] > key) // goes through the sorted part of the array, to find where to insert the value
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	for (size_t y = 0; y < len; y++)
	{
		std::cout << arr[y] << " ";
	}

	

}

int main()
{
	int arr[] = {1, 3, -1, 0, 5, 10, 6, 8, 7, 11, 14};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	insertion_sort(arr, len);
}

/* 
	Take the first value from the unsorted part of the array.
	Move the value into the correct place in the sorted part of the array.
	Go through the unsorted part of the array again as many times as there are values.

	for i in arr[1, len]:
		int key = arr[i]
		j = i -1; // get the previus elem to compare
		while (j >= 0 && key > arr[j])
		{
		}
*/