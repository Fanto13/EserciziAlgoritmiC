#include<limits.h>
#include<stdio.h>

/*soluzione con int max*/
void Merge_Int_Max(int *A, int left_index, int middle_index, int right_index) {
    int n1=middle_index - left_index +1;  //Dimensione array di sinistra
    int n2=right_index - middle_index;    //Dimensione array di destra
    int L[n1+1],R[n2+1];                  //Dichiaro array e aggiungo spazio per real_max
    int i,j=left_index;
    for (i=0; i<n1 ; i++){                //riempio array di sinistra con elementi a partire da left_index(uguale a 0solo al primo giro)
        L[i]=A[j];
        j++;
    }
    for (i=0; i<n2 ; i++){                //riempio secondo array a partire dalla j-esima posizione di A[]
        R[i]=A[j];
        j++;
    }
    L[n1]= INT_MAX;                       //Ultimi elementi dei due array eguagliati a real_max
    R[n2]= INT_MAX;

    i=0;j=0;
    int k;
    for(k=left_index;k<=right_index;k++)   //Riempimento ordinato di A[] in base al confronto dell'i-esimo con il j-esimo elemento
    {                                      // se inserisco i prossimo confronto con i+1-esimo elemento con j e viceversa
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
}

  void Merge_Int_Max_Sort(int *A, int left_index, int right_index) {
      if (left_index < right_index) //rompo array fino ad arrivare a casella unitaria
      {
          int middle_index= (left_index + right_index) / 2 ;
          Merge_Int_Max_Sort(A,left_index,middle_index);  //ordinamento su nuova parte dx
          Merge_Int_Max_Sort(A,middle_index+1 , right_index); //ordinamento su nuova parte sx
          Merge_Int_Max(A,left_index,middle_index,right_index); //inserimento ordinato delle due parti relative
                                                                //alla n-esima chiamata ricorsiva
      }
  }
  
int main(){
    int dim=11;
    int a[11]={22,2,29,17,33,7,10,48,1,33,59};
    int i;
    Merge_Int_Max_Sort(a,0,dim-1);
     for(i=0;i<10;i++)
        printf("%d ",a[i]);
}
