#include "sort.h"

size_t lomuto_partition(int *arr, size_t low, size_t high, size_t size)
{
	int pivot = arr[high];
	int i = low - 1, tmp;
	size_t j;

	for (j = low; j <= high - 1; j++)
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
	i++;
	tmp = arr[i];
	arr[i] = arr[high];
	arr[high] = tmp;

	return (i);
}

void quicksort_lomuto(int *arr, int low, int high, size_t size)
{
	size_t partition_index;

	if (low >= high || low < 0)
		return;

	partition_index = lomuto_partition(arr, low, high, size);
	quicksort_lomuto(arr, low, partition_index - 1, size);
	quicksort_lomuto(arr, partition_index + 1, high, size);
}

void quick_sort(int *array, size_t size)
{
	quicksort_lomuto(array, 0, size - 1, size);
}
