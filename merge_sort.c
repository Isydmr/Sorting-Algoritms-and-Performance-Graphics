#include <stdlib.h>

void merge(int *array, int low, int mid, int high) {
    int i, j, k;

    int n1 = mid - low + 1;
  /* Sol yarim listenin boyu */
    int n2 =  high - mid;
  /* Sag yarim listenin boyu */
    int L[n1], R[n2];
  /* Sol ve sag yarim liste icin dizi*/
    for (i = 0; i < n1; i++){
        L[i] = array[low + i];
    }
   /* Sol yarim listeyi sinirlarina gore doldur */
    for (j = 0; j < n2; j++){
        R[j] = array[mid + 1+ j];
    }
  /* Sag yarim listeyi sinirlarina gore doldur */
      i = 0;
      j = 0;
      k = low;

      while (i < n1 && j < n2)
      {
          if (L[i] <= R[j])
          {
              array[k] = L[i];
              i++;
          }
          else
          {
              array[k] = R[j];
              j++;
          }
          k++;
      }
      while (i < n1)
          {
              array[k] = L[i];
              i++;
              k++;
          }
  /* Birlestirme: Sol ve sag yarim listeleri kendi aralarinda
   * karsilastirarak listenin ilgili yerine yerlestir.
   * iki yarim listeden birinin sonuna gelindiginde donguden cik. */
      while (j < n2)
         {
             array[k] = R[j];
             j++;
             k++;
         }
  /* TODO: Yarim listelerin tum elemanlari listenin ilgili yerine
   * sokulmadiysa, kalan elemanlari yerlestirin. */
}

/* Bolme ve birlestirme metodunu gerceklestiren fonksiyon */
void merge_sort(int *array, int low, int high) {
  /* Eger elde kalan liste tek elemanli degilse */
	int mid;
  if (low < high) {
	  	 mid=(low+high)/2;
    /* Orta noktayi bul */
	   merge_sort(array,low,mid);        //left recursion
    /* Sol tarafi ozyinelemeli olarak sirala */
	   merge_sort(array,mid+1,high);    //right recursion
    /* Sag tarafi ozyinelemeli olarak sirala */
	    merge(array,low,mid,high);
    /* Siralanmis listeleri birlestir */
  }
}

void merge_sort_wrapper(int *array, int size) {
  merge_sort(array, 0, size - 1);
}
