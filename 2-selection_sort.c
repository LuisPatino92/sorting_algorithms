#include "sort.h"

/**
 * selection_sort - Sorts an array with a Selection Sort implementation
 *
 * @array: the array of integers to be sorted
 * @size: The size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t inf = 0, i = 0, j, tmp_index;
	int min;
	char swapped = 'n';

	if (array)
		while (i < size - 1)
		{
			swapped = 'n';
			inf++;
			min = array[i];
			tmp_index = array[inf];
			for (j = i + 1; j < size; j++)
				if (array[j] < min)
				{
					min = array[j];
					tmp_index = j;
					swapped = 'y';
				}
			if (swapped == 'y')
			{
				j = array[i];
				array[i] = min;
				array[tmp_index] = j;
				print_array(array, size);
			}
			i++;
		}
}
