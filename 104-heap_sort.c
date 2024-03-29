#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, big;

	left = 2 * root + 1;
	right = 2 * root + 2;
	big = root;

	if (left < base && array[left] > array[big])
		big = left;
	if (right < base && array[right] > array[big])
		big = right;

	if (big != root)
	{
		swap_ints(array + root, array + big);
		print_array(array, size);
		max_heapify(array, size, base, big);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int n;

	if (array == NULL || size < 2)
		return;

	for (n = (size / 2) - 1; n >= 0; n--)
		max_heapify(array, size, size, n);

	for (n = size - 1; n > 0; n--)
	{
		swap_ints(array, array + n);
		print_array(array, size);
		max_heapify(array, size, n, 0);
	}
}
