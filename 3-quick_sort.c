#include "sort.h"


void quick_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (size < 1)
		return;
	for (i = 1; i < size; i++)
	{
		min = i - 1;
		for (j = i; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i - 1)
		{
			tmp = array[min];
			array[min] = array[i - 1];
			array[i - 1] = tmp;
			print_array(array, size);
		}
	}
}
