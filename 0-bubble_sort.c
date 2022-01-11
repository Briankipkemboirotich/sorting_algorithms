#include "sort.h"

/**
 * bubble_sort - function that sorts an array in ascending order.
 * @array: List of integers
 * @size: Lenght of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
  size_t x, y;
  int temp;

  if (!array || size < 2)
    return;
  for (x = 0; x < size - 1; x++)
    {
      for (y = 0; y < size - 1 - x; y++)
	{
	  if (array[y] > array[y + 1])
	    {
	      temp = array[y];
	      array[y] = array[y + 1];
	      array[y + 1] = temp;
	      print_array(array, size);
	    }
	}
    }

}
