#include "sort.h"
/**
 * maximum - search for the maximum integer
 * @array: List of integers
 * @size: lenght of the array
 * Return: Nothing
 */
size_t maximum(int *array, int size)
{

  int x = 0;
  int max = 0;

  for (x = 0; x < size; x++)
    {
      if (array[x] > max)
	{
	  max = array[x];
	}
    }

  return ((size_t)max);
}

/**
 * counting_sort - sorts an array ascending order, Counting sort algorithm
 * @array: List of integers
 * @size: lenght of the array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{

  size_t x, max = maximum(array, size);
  int counting_array[10000];
  int array2[10000];
  int num = 0, tmp;

  for (x = 0; x < 10000 - 1; x++)
    counting_array[x] = '\0';

  if (!array || size < 2)
    return;
  for (x = 0; x < size; x++)
    counting_array[array[x]]++;
  for (x = 0; x < size; x++)
    array2[array[x]]++;
  for (x = 0; x <= max; x++)
    {
      tmp = counting_array[x];
      counting_array[x] += num;
      num += tmp;
    }
  print_array(counting_array, max + 1);
  num = 0;
  x = 0;
  while (x < size)
    {
      while (array2[num] > 0)
	{
	  array[x] = num;
	  array2[num]--;
	  x++;
	  if (x > size)
	    {
	      break;
	    }
	}
      num++;
    }
}
