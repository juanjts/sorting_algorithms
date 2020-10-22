#include "sort.h"
/**
 * swap - Function name.
 * @a: First value to swap
 * @b: Second value to swap
 *
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Function name.
 * @arr: The array to be sorted
 * @low: First position of the array
 * @high: Last position of the array
 * @size: Number of elements in @arr
 * Return: a int data that indicates the pivot position.
 */
int partition(int *arr, size_t size, int low, int high)
{
	int i;
	int j;
	int pivot;

	pivot = arr[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[j], &arr[i]);
				print_array(arr, size);
			}
		}
	}
	i++;
	if (i != j && arr[i] != arr[j])
	{
		swap(&arr[high], &arr[i]);
		print_array(arr, size);
	}
	return (i);
}

/**
 * quicksrt - Function name.
 * @arr: The array to be sorted
 * @low: First position of the array
 * @high: Last position of the array
 * @size: Number of elements in @arr
 */
void quicksrt(int *arr, size_t size, int low, int high)
{
	int piv;

	if (low < high)
	{
		piv = partition(arr, size, low, high);
		quicksrt(arr, size, low, piv - 1);
		quicksrt(arr, size, piv + 1, high);
	}
}

/**
 * quick_sort - Function name.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksrt(array, size, 0, size - 1);
}
