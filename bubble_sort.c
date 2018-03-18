#include <stdlib.h>
void bubble_sort(int *array, int size)
{
  int c, d, t;

  for (c = 0 ; c < ( size - 1 ); c++)
  {
    for (d = 0 ; d < size - c - 1; d++)
    {
      if (array[d] > array[d+1])
      {
        t         = array[d];
        array[d]   = array[d+1];
        array[d+1] = t;
      }
    }
  }
}
