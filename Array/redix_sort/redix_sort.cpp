#include <iostream>

void	redix_sort(int arr[], size_t size)
{
	int max_val = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max_val)
			max_val = arr[i];
	}
	
	int *redix_arr[10];
	for (int i = 0; i < 10; ++i)
	{

		redix_arr[i] = new int[size](); // calls value initialization, Initialize each bucket with zeros
		//redix_arr[i] = new int[size]; // calls default constructor

	}
	
	int exp = 1;
	int count_i[10] = {0}; //[i:0-9][list of equal index]
	while (max_val / exp > 0) // iterate between digit. yekan, dahgan, sadgan
	{
		for (size_t i = 0; i < size; i++)
		{
			int index = (arr[i] / exp) % 10; // refer to the note book, why it has used exp?
			redix_arr[index][count_i[index]++] = arr[i];
		}
		int pos = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0 ; j < count_i[i]; j++) // from inner, pop from end or from start?
			{
				arr[pos++] = redix_arr[i][j];
			}
			count_i[i] = 0;
		}
		exp *= 10;
	}
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	for (size_t i = 0; i < 10; i++)
	{
		delete[] redix_arr[i];
	}
	std::cout << std::endl;
}

int main()
{
	int arr[] = {0, 15, 11, 10, 8, 7, 14, 17, 22, 5, 9};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	redix_sort(arr, size);
	int exp = 1;
	std::cout << (19 / exp) % 10 << std::endl;
}