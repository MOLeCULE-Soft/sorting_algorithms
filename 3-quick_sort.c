#include "sort.h"

size_t lomuto_partition(int *arr, size_t low, size_t high, size_t size)
{
	int pivot = arr[high];
	int i = low - 1, tmp;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			print_array(arr, size);
		}
	}
	printf("We are here\n");
	pivot =  arr[i + 1];
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;

	return (i + 1);
}

void quicksort_lomuto(int *arr, size_t low, size_t high, size_t size)
{
	size_t partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(arr, low, high, size);
		quicksort_lomuto(arr, low, partition_index - 1, size);
		quicksort_lomuto(arr, partition_index + 1, high, size);
	}
}

void quick_sort(int *array, size_t size)
{
	quicksort_lomuto(array, 0, size - 1, size);
}
