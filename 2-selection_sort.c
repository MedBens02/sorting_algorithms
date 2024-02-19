#include "sort.h"

/**
 * selection_sort - Sort an array of ints using selection sort
 * @array: the array to sort
 * @size: its size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size + 1; i++)
	{
		idx = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[idx])
				idx = j;

		if (idx != i)
		{
			tmp = array[idx];
			array[idx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
