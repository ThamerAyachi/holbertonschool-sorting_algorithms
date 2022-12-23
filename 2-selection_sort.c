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
	size_t i, j, tmp, flag = 0;

	if (size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		tmp = i;
		for (j = i; j < size; j++)
		{
			if (array[tmp] > array[j])
			{
				tmp = j;
				flag++;
			}
		}
		swap(array, tmp, i);
		if (flag != 0)
			print_array(array, size);
	}
}
