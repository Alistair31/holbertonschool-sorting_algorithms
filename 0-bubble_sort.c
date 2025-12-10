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
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
