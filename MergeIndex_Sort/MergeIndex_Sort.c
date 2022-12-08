#include<limits.h>
#include<stdio.h>
#include"Verifica.h"
/*soluzione con Index*/
void MergeIndex(int *A, int left_index, int middle_index, int dimensione) {
    int n1=middle_index - left_index +1;  //Dimensione array di sinistra
    int n2=dimensione - middle_index;    //Dimensione array di destra
    int L[n1],R[n2];                  //Dichiaro array e aggiungo spazio per real_max
    int i,j=left_index;
    for (i=0; i<n1 ; i++){                //riempio array di sinistra con elementi a partire da left_index(uguale a 0solo al primo giro)
        L[i]=A[j];
        j++;
    }
    for (i=0; i<n2 ; i++){                //riempio secondo array a partire dalla j-esima posizione di A[]
        R[i]=A[j];
        j++;
    }

    i=0;j=0;
    int k=left_index;
    while(i<n1 && j<n2)   //Riempimento ordinato di A[] in base al confronto dell'i-esimo con il j-esimo elemento
    {                                      // se inserisco i prossimo confronto con i+1-esimo elemento con j e viceversa
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
            k++;
        }
        else
        {
            A[k]=R[j];
            j++;
            k++;
        }
    }
    if (i==n1)
    {
        for(j;j<n2;j++)
            A[k]=R[j];
            k++;
    }
    else
        if (j==n2)
        {
            for(i;i<n2;i++)
                A[k]=L[i];
                k++;
        }
}

  void MergeIndex_Sort(int *A, int left_index, int dimensione) {
      if (left_index < dimensione) //rompo array fino ad arrivare a casella unitaria
      {
          int middle_index= (left_index + dimensione) / 2 ;
          MergeIndex_Sort(A,left_index,middle_index);  //ordinamento su nuova parte dx
          MergeIndex_Sort(A,middle_index+1 , dimensione); //ordinamento su nuova parte sx
          MergeIndex(A,left_index,middle_index,dimensione); //inserimento ordinato delle due parti relative
                                                                //alla n-esima chiamata ricorsiva
      }
  }
  
int main(){
    Crea_Array();
    MergeIndex_Sort(A,0,DIMENSIONE-1);
    MergeIndex_Sort(B,0,DIMENSIONE-1);
    Verifica();
    Stampa();
}
