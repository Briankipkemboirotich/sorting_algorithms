#include "sort.h"

/**
 * shell_sort - sorts an array on ascending order, Shell sort algorithm
 * @array: List of integers
 * @size: Lenght of the array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
  size_t x, y, d = 1;
  int temp;

  if (size < 2)
    return;
  while (d < size)
    d = d * 3 + 1;
  d = (d - 1) / 3;
  for (; d > 0; d = (d - 1) / 3)
    {
      for (x = d; x < size; x++)
	{
	  temp = array[x];
	  for (y = x; y >= d && array[y - d] > temp; y = y - d)
	    array[y] = array[y - d];
	  array[y] = temp;
	}
      print_array(array, size);
    }
}
