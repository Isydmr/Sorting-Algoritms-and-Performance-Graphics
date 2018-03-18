#include <stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// TODO 


int partition(int *array, int low, int high) {
// TODO 
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort(int *array, int low, int high) {
	   if (low < high)
	    {
	        /* pi INDEXXX is partitioning index, arr[p] is now
	           at right place */
	        int pi = partition(array, low, high);

	        quick_sort(array, low, pi - 1);
	        quick_sort(array, pi + 1, high);
	    }
}
void quick_sort_gsu(int *array, int size) {
	  quick_sort(array, 0, size - 1);

}
