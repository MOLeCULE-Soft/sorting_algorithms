#include "sort.h"

/**
 * bubble_sort - Sorting Aglo
 * @array: to be sorted
 * @size: of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	int tmp;
	bool repeat = true;

	while (repeat)
	{
		repeat = false;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				repeat = true;
				print_array(array, size);
			}
		}
		n--;
	}
}
