#include "sort.h"


void swapInt(int *x, int *y);
size_t lomutoPart(int *array, size_t size, ssize_t L, ssize_t H);
void qSort(int *array, size_t size, ssize_t L, ssize_t H);


/**
 * swapInt - swaps 2 ints
 * @x: first int
 * @y: second int
 */
void swapInt(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomutoPart - partitions the array using lomuto scheme
 * @array: the array to sort
 * @size: its size
 * @L: lowest index
 * @H: highrst index
 *
 * Return: idx of the new pivot
 */
size_t lomutoPart(int *array, size_t size, ssize_t L, ssize_t H)
{
	int i = L, j, pivot = array[H];

	for (j = L; j < H; j++)
	{
		if (array[j] < pivot)
		{
			swapInt(&array[i], &array[j]);
			i++;
			print_array(array, size);
		}
	}
	swapInt(&array[i], &array[H]);
	print_array(array, size);

	return (i);
}


/**
 * qSort - Implements the quick sort algorithm
 * @array: the array to sort
 * @size: its size
 * @L: lowest idx
 * @H: highest idx
 */
void qSort(int *array, size_t size, ssize_t L, ssize_t H)
{
	size_t idx;

	if (L < H)
	{
		idx = lomutoPart(array, size, L, H);

		qSort(array, size, L, idx - 1);
		qSort(array, size, idx + 1, H);
	}
}


/**
 * quick_sort - Sorts an array of ints using quick sort
 * @array: the array to sort
 * @size: its size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qSort(array, size, 0, size - 1);
}
