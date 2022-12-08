#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DIMENSIONE 10000


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
    int i = left_index-1;	//decremento i come da pseudo-codice
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
 
/* QUICK SORT */

/*suddivisione array*/
int Random_Partition(int *a,int left_index,int dimensione)
{
    int l=rand()%(dimensione-left_index) +left_index;
    int x=a[l];	//elemento di confronto
	Scambia(&a[l],&a[dimensione-1]);
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

/*quick sort base che usa RandomPartition*/
void Random_Quick_Sort(int *a,int left_index,int dimensione)
{
    if(left_index<dimensione)		// lo faccio fino a quando non ho insieme unitario
    {
        int compare_index=Random_Partition(a,left_index,dimensione); //	mi ritorna indice (in A[]) dell'elemento di comparazione
        Random_Quick_Sort(a,left_index,compare_index);	// Applico Random_Quick_Sort su insieme sx
        Random_Quick_Sort(a,compare_index+1,dimensione);	// Applico Random_Quick_Sort su insieme dx
    }
}


void CreaArray(int *A,int *B)
{
    int j=DIMENSIONE;
    for (int i=0;i<DIMENSIONE;i++)
    {
        A[i]=j;
        B[i]=j;
        j--;
    }
}
void Stampa(int *A)
{
    for(int i=0;i<DIMENSIONE;i++)
    {
        printf("%d ",A[i]);
    }
}


int main()
{
    int S[DIMENSIONE];
    int R[DIMENSIONE];
    
    CreaArray(S,R);
    
    clock_t inizio,fine,standard,random;
    inizio=clock();
    Standard_Quick_Sort(S,0,DIMENSIONE);
    fine=clock();
    standard=fine-inizio;
    inizio=clock();
    Random_Quick_Sort(R,0,DIMENSIONE);
    fine=clock();
    random=fine-inizio;

    printf("\nStandard= %ld\nRandom= %ld\n\n",standard,random);
    /*
    Stampa(S);
    printf("\n");
    Stampa(R);
    printf("\n");
    */
}