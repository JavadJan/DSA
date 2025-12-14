#include <stdio.h>

void bubble_sort(int arr[], int len)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (size_t j = 0; j < len ; j++)
	{
		printf(" %d,", arr[j]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {1, 3, -1, 0, 5, 10, 6, 8, 7, 11, 14};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, len);
	return (0);
}

/* spdoudo code:
	while (i < len - 1)
	{
		while (j < len - i -1) // every time decreas the length and one placed in the right place
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i + 1] = arr[i];
				arr[i + 1] = temp;
			}
		}
		i++;
	}
*/