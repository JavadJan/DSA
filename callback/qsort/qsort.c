#include <stdio.h>
#include <stdlib.h>

void q_sort(int arr)
{
    size_t size;
    int pivot;
    int *left;
    int *right;
    int j = 0;
    int z = 0;

    ptivot = arr[0];
    size = sizeof(arr) / sizeof(arr[0]);
    if (size == 1)
        return (arr);
    
    while (i < size)
    {
        if (arr[i] < pivot)
        {
            left[j] = arr[i];
            j++;
        }
        else if (arr[i] > pivot)
        {
            right[z] = arr[i];
            z++;
        }
        i++;
    }

}
int compare(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int arr = {5, 6, 2, 1, 3, 4};
    int size;
    int i = 0;

    size = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, size, sizeof(int), compare);
    while (i < size)
        printf("element %d is %d", i, arr[i]);
    return (0);
}