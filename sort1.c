#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Insertion_sort(int *array, int p, int dimensione);
void Visualizza(int *array,int dimensione);
void mergesort(int *array, int left, int right);
void merge(int *array, int p, int q, int r);
void mixedSort(int *array, int left, int right);

int main(){
    
    int i,j;
    int r,N;
    int iterazioni;
    clock_t inizioMerge, fineMerge;
    clock_t inizioMixed, fineMixed;
    float medioMerge=0, medioMixed=0;
    srand((unsigned)time(NULL)); 

    printf("numero ripetizioni del ciclo");
    scanf("%d",&iterazioni);
    for(j=0; j<iterazioni; j++)
    {
        N=20000;
        int array[N],copiarray[N];
        
        for(i=0; i<N; i++)
        {
            // variabile che assegno i valori random e poi passo agli array da riempire
            r=rand() % 400;
            array[i]=r;
            copiarray[i]=r;
        }

        //printf("array disordinato\n");
        //Visualizza(array,N);// stampa vettore non ordinato
        //printf("\n");
	
        // da qua inizio a calcolare i tempi del merge sort che devo confrontare con il mixed
        inizioMerge=clock();
        //al mergesort passo il mio array contenente gli elementi random 0 che sarebbe la posizione di left e la dimensione a righe (N-1)
        mergesort(array,0,N-1);
        fineMerge=clock();
        
        inizioMixed=clock();
        mixedSort(copiarray,0,N-1);
        fineMixed=clock();
        //ho controllato che l'array sia ordinato (è ordinato)
        //printf("\n");
        //Visualizza(array,N);
        
        medioMerge=medioMerge+(fineMerge-inizioMerge);
        
        medioMixed=medioMixed+(fineMixed-inizioMixed);

      }
	
        //tempo medio da trasformare in secondi
        printf("\n");
        printf("il tempo medio in secondi per Merge_Sort è : %f\n",(float)(medioMerge)/CLOCKS_PER_SEC);        
        printf("il tempo medio in secondi per il Mixed_Sort è : %f\n",(float)(medioMixed)/CLOCKS_PER_SEC);
	
        return 0;
}

void insertion_sort(int *array,int p,int dimensione) {
  int i, j, key;

  for (i=p+1; i<dimensione; i++) {
    key = array[i];
    j = i-1;
    while (j>=p && array[j]>key) { 
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
}

void Visualizza(int *array,int dimensione)
{
    int i;
    for(i=0; i<dimensione; i++)
    {
	
        printf("%d ",array[i]);

    }
}

void mergesort(int *array, int left, int right)
{

	// indice dell' elemento in pozione centrale 

	int center;
	
	//controllare che ci siano almeno due elementi nel vettore 

	if(left<right)

	{

		center=(left+right)/2;// divido il vettore 

		mergesort( array, left, center); // chiamo la funzione merge per la prima parte 
	
		mergesort (array, center+1, right); // chiamo la funzione di ordinamento per la seconda parte 

		merge (array, left, center, right); // chiamo la funzione per l'unione della seconda parte da ordinare 
		

	}
}

void mixedSort(int *array, int left, int right)
{
    int center;
    
    if(30<=right-left)
    {
    
        //divido il vettore in 2 parti
        center=(left+right)/2;
        //chiamo la funzione per la prima metà
        mixedSort(array,left,center);
        //chiamo la funzione di ordinamento per la seconda metà
        mixedSort(array, center+1, right);
        //chiamo la funzione per la fusione delle 2 metà ordinate
        merge(array, left, center, right);
    }
    else
    {
      
        // prende left come primo elemento da ordinare indipendentemente da dove si trova e right come ultimo elemento
        insertion_sort(array,left,right+1);// right +1 per prendere tutto il vettore
    }
}

void merge (int *array, int p , int q, int r )
{

int n1=q-p+1;//
int n2=r-q;// 
 
	int left[n1],right[n2], i=0, j=0, k=0;

	//copio la parte sinistra in left 

	for(i=0; i<n1; i++)
	{
		left[i]=array[i+p];
	}
	
	left[n1]= 2147483647; //massimo numero rappresentabile 

	// copio la parte destra in right 

	for (j=0 ; j< n2; j++)
	{
		right[j]=array[j+q+1];
	}


	right[n2]=2147483647;

	// unisco i due vettori

	i=0;
	j=0;

	for (k=p; k<=r; k++)
	{
			if(left[i]<= right[j])
			{
			array[k]=left[i];
			i++;
			}
			else 
			{
				array[k]=right[j];
				j++;
			}

	}

}





	







