#include<stdio.h>
void Scambia(int *c,int *b)
{
    int temp;
    temp=*c;
    *c=*b;
    *b=temp;
}
void Stampa(int *A,int dimensione)
{
    for(int i=0;i<dimensione;i++)
      printf("%d ",A[i]);
}
/* QUICK SORT */

/*suddivisione array*/
int Standard_Partition(int *a,int left_index,int right_index)
{
    int x=a[right_index-1];	//elemento di confronto
    int i = left_index-1;		//decremento i come da pseudo-codice
    for(int j=left_index;j<right_index-1;j++) //scorro fino a n-1 perchè n-esimo elemento è di confronto
    {
        if (a[j]<=x)		//se elemento j-esimo è minore lo scambia, ma se è già ordinato lo scambia con se stesso
        {
            i++;
            Scambia(&a[i],&a[j]);
        }
    }
    i++;
    Scambia(&a[i],&a[right_index-1]); //metto elemento di confronto a separare i due insiemi
return i;
}

/*quick sort base che usa standardPartition*/
void Standar_Quick_Sort(int *a,int left_index,int right_index)
{
    if(left_index<right_index)		// lo faccio fino a quando non ho insieme unitario
    {
        int compare_index=Standard_Partition(a,left_index,right_index); //	mi ritorna indice (in A[]) dell'elemento di comparazione
        Standar_Quick_Sort(a,left_index,compare_index);	// Applico Standar_Quick_Sort su insieme sx
        Standar_Quick_Sort(a,compare_index+1,right_index);	// Applico Standar_Quick_Sort su insieme dx
    }
}

int main(){
    int a[10]=/*0{6,6,4,3,5,7,9,2,8,0};*/{0,2,9,8,25,8,74,21,11,100};
    int p=0;
    int r=10;
    Standar_Quick_Sort(a,p,r);
    Stampa(a,r);


return 0;
}
