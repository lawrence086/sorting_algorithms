#include "sort.h"

/**
 *
 * _bigest - Returns the largest integer in an array
 *
 * @a: The integer array
 *
 * @size: Size of the array
 *
 * Return: The largest integer
 * */
int _bigest(int *a, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < a[i])
			k = a[i];
	}
	return (k);
}

/**
 *
 * _memset - Creates an integer array and sets each element to zero
 *
 * @size: Size of the array
 *
 * Return: The integer array
 * */
int *_memset(int size)
{
	int *ptr = NULL;
	int i;

	ptr = malloc((size) * sizeof(int));

	for (i = 0; i < size; i++)
		ptr[i] = 0;

	return (ptr);
}

/**
 *
 * counting_sort - Sorts an array using the counting sort algorithm
 *
 * @array: The integer array to be sorted
 *
 * @size: Size of the array
 *
 * Return: The sorted array
 * */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int k = 0;
	int *aux = NULL, *array_sort = NULL;

	if (size < 2)
		return;

	/* Find the largest number in the array */
	k = _bigest(array, size);

	/* Create an auxiliary array initialized with zeros */
	aux = _memset(k + 1);
	if (!aux)
		return;

	/* Set the values to be sorted */
	for (i = 0; i < size; i++)
		for (j = 0; (int)j < k + 1; j++)
			if ((int)j == array[i])
				aux[j] += 1;

	/* Modify the count in the array */
	for (i = 0; (int)i < k; i++)
		aux[i + 1] = aux[i] + aux[i + 1];

	/* Create the sorted array */
	array_sort = malloc(size * sizeof(int));
	if (!array_sort)
	{
		free(aux);
		return;
	}
	for (i = 0; i < size; i++)
	{
		array_sort[aux[array[i]] - 1] = array[i];
		aux[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = array_sort[j];

	free(array_sort);
	free(aux);
}
