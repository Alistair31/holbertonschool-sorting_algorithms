#include "sort.h"
/**
 * swap - Échange deux entiers dans un tableau
 * @a: Premier entier
 * @b: Deuxième entier
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partition Lomuto pour Quick sort
 * @array: Tableau à partitionner
 * @low: Index de début de la partition
 * @high: Index de fin de la partition (pivot)
 * @size: Taille totale du tableau (pour l'affichage)
 *
 * Return: Position finale du pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Fonction récursive de Quick sort
 * @array: Tableau à trier
 * @low: Index de début
 * @high: Index de fin
 * @size: Taille totale du tableau
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{

		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);

		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Trie un tableau d'entiers en ordre croissant
 *              en utilisant l'algorithme Quick sort
 * @array: Tableau à trier
 * @size: Taille du tableau
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
