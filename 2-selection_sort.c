#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int m_tmp;

	m_tmp = *a;
	*a = *b;
	*b = m_tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minum;
	size_t n, m;

	if (array == NULL || size < 2)
		return;

	for (n = 0; n < size - 1; n++)
	{
		minum = array + n;
		for (m = n + 1; m < size; m++)
			minum = (array[m] < *minum) ? (array + m) : minum;

		if ((array + n) != minum)
		{
			swap_ints(array + n, minum);
			print_array(array, size);
		}
	}
}
