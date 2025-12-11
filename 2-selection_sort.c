#include "sort.h"
#include <stdio.h>
/**
 * swap_int - check the code
 * @a: first integer in function
 * @b: second integer to swap with the first
 * Return: Always 0.
 */
void swap_int(int *a, int *b)
{
	int trf = 0;

	trf = *b;
	*b = *a;
	*a = trf;
}

/**
 * selection_sort - Sorts with selection an array in ascending order
 * @array: Pointer to the array of integers to be sorted.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t jMin;

	for (i = 0; i < size - 1; i++)
	{
		jMin = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}
		if (jMin != i)
		{
			swap_int(&array[i], &array[jMin]);
			print_array(array, size);
		}
	}
}
