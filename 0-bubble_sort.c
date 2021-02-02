#include "sort.h"

/**
 * bubble_sort - Sorts an array with a Buble Sort implementation
 * @array: The array to be sorted
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	char swapped = 'n';
	int aux = 0;
	size_t i, max_limit = size - 1;

	if (array && size > 0)
		do {
			swapped = 'n';
			for (i = 0; i < max_limit; i++)
			{
				if (*(array + i) > *(array + i + 1))
				{
					aux = *(array + i);
					*(array + i) = *(array + i + 1);
					*(array + i + 1) = aux;
					print_array(array, size);
					swapped = 'y';
				}
			}
			max_limit--;
		} while (swapped != 'n');
}
