#include "sort.h"

void swap(int *array, size_t size, size_t bigger, size_t smaller);

/**
 * selection_sort - implements selection sort in c
 * @array: an array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t start = 0;
	int smallest = 0;
	size_t i = 0;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		size_t j = i;

		smallest = i;
		while (j < size)
		{
			if (array[j] < array[smallest])
				smallest = j;
			j++;
		}
		if (array[start] > array[smallest])
		{
			swap(array, size, start, smallest);
		}
		start++;
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
