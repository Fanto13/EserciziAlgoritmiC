#include<stdio.h>
#include"Verifica.h"
void Scambia(int *c,int *b)
{
    int temp;
    temp=*c;
    *c=*b;
    *b=temp;
}

/* QUICK SORT */

/*suddivisione array*/
int Standard_Partition(int *a,int left_index,int dimensione)
{
    int x=a[dimensione-1];	//elemento di confronto
    int i = left_index-1;		//decremento i come da pseudo-codice
    for(int j=left_index;j<dimensione-1;j++) //scorro fino a n-1 perchè n-esimo elemento è di confronto
    {
        if (a[j]<=x)		//se elemento j-esimo è minore lo scambia, ma se è già ordinato lo scambia con se stesso
        {
            i++;
            Scambia(&a[i],&a[j]);
        }
    }
    i++;
    Scambia(&a[i],&a[dimensione-1]); //metto elemento di confronto a separare i due insiemi
return i;
}

/*quick sort base che usa standardPartition*/
void Standard_Quick_Sort(int *a,int left_index,int dimensione)
{
    if(left_index<dimensione)		// lo faccio fino a quando non ho insieme unitario
    {
        int compare_index=Standard_Partition(a,left_index,dimensione); //	mi ritorna indice (in A[]) dell'elemento di comparazione
        Standard_Quick_Sort(a,left_index,compare_index);	// Applico Standard_Quick_Sort su insieme sx
        Standard_Quick_Sort(a,compare_index+1,dimensione);	// Applico Standard_Quick_Sort su insieme dx
    }
}

int main(){
    Crea_Array();
    Standard_Quick_Sort(A,0,DIMENSIONE);
    Standard_Quick_Sort(B,0,DIMENSIONE);
    Verifica();


return 0;
}
