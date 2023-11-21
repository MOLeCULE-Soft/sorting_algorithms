#include "sort.h"

/**
 * merge - for merge sort
 * @arr: array
 * @left: portion of @arr
 * @mid: of @arr
 * @right: portion of arr
*/
void merge(int arr[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L, *R;

	L = malloc(sizeof(int) * n1);
	R = malloc(sizeof(int) * n2);

	printf("Merging...\n");
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
	i = j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
	printf("[left]: ");
	print_array(L, n1);
	printf("[right]: ");
	print_array(R, n2);
	free(L);
	free(R);
	printf("[Done]: ");
	print_array(arr, right - left + 1);
}

/**
 * mergeSort - top down approach
 * @arr: array
 * @left: portion of @arr
 * @right: portion of arr
*/
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

/**
 * merge_sort - Sorting Aglo
 * @array: to be sorted
 * @size: of array
*/
void merge_sort(int *array, size_t size)
{
	mergeSort(array, 0, size - 1);
}
