#include "sort.h"

/**
 * counting_sort - Sorting algo
 * @array: to be sorted
 * @size: of @array
*/
void counting_sort(int *array, size_t size)
{
	size_t max;
	int i, j, count, *count_array, *res_arr;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > (int)max)
			max = array[i];

	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
		return;
	memset(count_array, 0, sizeof(int) * (max + 1));
	for (i = 0; i < (int)(max + 1); i++)
	{
		count = 0;
		for (j = 0; j < (int)size; j++)
			if (array[j] == (int)i)
				count++;
		count_array[i] = count;
		if (i > 0)
			count_array[i] += count_array[i - 1];
	}
	print_array(count_array, (max + 1));
	res_arr = malloc(sizeof(int) * size);
	if (!res_arr)
	{
		free(count_array);
		return;
	}
	j = size;
	while (--j >= 0)
		res_arr[--count_array[array[j]]] = array[j];
	memcpy(array, res_arr, sizeof(int) * size);
	free(count_array);
	free(res_arr);
}
