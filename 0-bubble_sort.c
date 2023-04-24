#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 *                Bubble sort algorithm.
 *                @array: The array of integers to be sorted.
 *                @size: The size of the array to be sorted.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
