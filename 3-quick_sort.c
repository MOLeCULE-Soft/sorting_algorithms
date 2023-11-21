#include "sort.h"

size_t lomuto_partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low - 1, tmp;
	int j;
	printf("First i = %d\n", i);
	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			printf("Inside...[%d, %d]\n", i, j);
			print_array(arr, size);
		}
	}
	i++;
	if (arr[i] > arr[high])
	{
		tmp = arr[i];
		arr[i] = arr[high];
		arr[high] = tmp;
		printf("Outside...\n");
		print_array(arr, size);
	}

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
