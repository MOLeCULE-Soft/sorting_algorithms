#include "sort.h"

/**
 * shell_sort - Sorting Aglo
 * @array: to be sorted
 * @size: of array
*/
void shell_sort(int *array, size_t size)
{
	int i, j;
	int tmp, gap;

	if (size < 1)
		return;

	gap = 1;
	while (gap <= (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
