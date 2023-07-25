#include "sort.h"

void swap(int *array, size_t size, size_t bigger, size_t smaller);

/**
 * bubble_sort - implements the bubbles sort algo in c
 * @array: an array of integers
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;

	if (array == NULL || size == 0 || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
				swap(array, size, j, j + 1);
		}
	}
}


/**
 * swap - swaps tow elements of an array
 * @array: the array holding the elements
 * @size: size of the array
 * @bigger: the bigger element
 * @smaller: the smaller element
 */
void swap(int *array, size_t size, size_t bigger, size_t smaller)
{
	int temp;

	temp = array[bigger];
	array[bigger] = array[smaller];
	array[smaller] = temp;

	print_array(array, size);
}
