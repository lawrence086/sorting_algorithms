#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array of integers in ascending
 * order using the Shell sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the gap using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* Sort elements at gap intervals */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		/* Print the array after each gap decrease */
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
