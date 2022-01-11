#include "sort.h"

/**
 * m_pri - function to sort an array using merge sort
 *@a: is the array
 *@aux: buffer
 *@l_i: first number of left side
 *@l_m: midle number at the left side
 *@r_i: first number of right side
 *@r_m: midel number at right side
 *Return: nothing
 */

void m_pri(int *a, int *aux, size_t l_i, size_t l_m, size_t r_i, size_t r_m)
{
  size_t left, l_size, right, r_size, i;

  left = l_i;
  l_size = l_m - l_i + 1;
  right = r_i;
  r_size = r_m - r_i + 1;
  i = l_i;

  printf("Merging...\n");
  printf("[left]: ");
  print_array(a + left, l_size);
  printf("[right]: ");
  print_array(a + right, r_size);

  while (l_i <= l_m && r_i <= r_m)
    {
      if (a[l_i] <= a[r_i])
	aux[i++] = a[l_i++];
      else
	aux[i++] = a[r_i++];
    }
  while (l_i <= l_m)
    aux[i++] = a[l_i++];
  while (r_i <= r_m)
    aux[i++] = a[r_i++];

  for (i = left; i <= r_m; i++)
    a[i] = aux[i];

  printf("[Done]: ");
  print_array(a + left, l_size + r_size);
}


/**
 * recursive_func - Function to changfe the number
 *@array: is the array
 *@aux: buffer
 *@init: start point
 *@max: the last position
 *Return: nothing
 */

void recursive_func(int *array, int *aux, size_t init, size_t max)
{
  if (max > init)
    {
      recursive_func(array, aux, init, (init + max + 1) / 2 - 1);
      recursive_func(array, aux, (init + max + 1) / 2, max);
      m_pri(array, aux, init, (init + max + 1) / 2 - 1,
	    (init + max + 1) / 2, max);
    }
}


/**
 *merge_sort - funtion that sort
 *@array: is the array
 *@size: the lenght of array
 *Return: nothing
 */

void merge_sort(int *array, size_t size)
{
  int aux[10000];

  if (!array || size < 2)
    return;
  recursive_func(array, aux, 0, size - 1);
}
