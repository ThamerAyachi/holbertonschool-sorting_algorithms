#include "sort.h"

/**
 * swap - swap two elements in array
 * @array: list of integers
 * @x: integer
 * @y: integer
 *
 * Return: integer
 */
int swap(int *array, int x, int y)
{
	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;

	return ((tmp == array[x]) ? 0 : 1);
}

/**
 * partition - third method
 * @array: array
 * @lower: int
 * @higher: int
 * @size: size_t
 * Return: int
 */
int partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			if (swap(array, i, j) == 1)
				print_array(array, size);

			++i;
		}
	}

	if (swap(array, i, higher) == 1)
		print_array(array, size);

	return (i);
}

/**
 * quick_sort_rec - second method
 * @array: array
 * @lower: int
 * @higher: int
 * @size: size_t
 */
void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
	int l_p = 0;

	if (lower < higher)
	{
		l_p = partition(array, lower, higher, size);
		quick_sort_rec(array, lower, l_p - 1, size);
		quick_sort_rec(array, l_p + 1, higher, size);
	}
}

/**
 * quick_sort - sort method
 * @array: array
 * @size: size_t
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
