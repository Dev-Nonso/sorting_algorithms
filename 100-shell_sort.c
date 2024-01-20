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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t ascen, n, m;

	if (array == NULL || size < 2)
		return;

	for (ascen = 1; ascen < (size / 3);)
		ascen = ascen * 3 + 1;

	for (; ascen >= 1; ascen /= 3)
	{
		for (n = ascen; n < size; n++)
		{
			m = n;
			while (m >= ascen && array[m - ascen] > array[m])
			{
				swap_ints(array + m, array + (m - ascen));
				m -= ascen;
			}
		}
		print_array(array, size);
	}
}
