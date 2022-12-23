#include "sort.h"

/**
 * swap - swap two elements in array
 * @array: list of integers
 * @x: integer
 * @y: integer
 */
void swap(int *array, int x, int y)
{
	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}

/**
 * selection_sort - sort method
 * @array: list of integers
 * @size: number of elements
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp;

	for (i = 0; i < size - 1; i++)
	{
		tmp = i;
		for (j = i; j < size; j++)
		{
			if (array[tmp] > array[j])
				tmp = j;
		}
		swap(array, tmp, i);
		print_array(array, size);
	}
}
