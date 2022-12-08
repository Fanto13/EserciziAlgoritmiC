//define che serve per poter usare la vecchia scanf
//con visual studio 2015
//#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_LUNGHEZZA 20000
#define NUM_ESPERIMENTI 10  	//ripetizione di tutti gli esperiment
#define REP_PER_ESPERIMENTO 10      
#define SALTO 2000   //variazione lunghezza array

/*Nota: SALTO*NUM_ESPERIMENTI deve essere <= MAX_LUNGHEZZA */

#define K 10 //parametro per la hybrid sort

//creazione di array di int ed element casuali di lunghezza n
void CreaArray(int *a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (n * 10);;
	}
}


/*************************************/
/* COPIA DI UN ARRAY di INT DI LUNGHEZZA n IN UN ALTRO*/
void CopiaArray(int *a1, int *a2, int n) {
	for (int i = 0; i<n; i++) a2[i] = a1[i];
}
/*************************************/


/*************************************/
/* STAMPA UN ARRAY DI LUNGHEZZA n */
void StampaArray(int *a, int n) {
	for (int i = 0; i<n - 1; i++) printf("%d, ", a[i]);
	printf("%d\n", a[n - 1]);
}
/*************************************/
/*************************************/
/* INSERTION SORT */
void insertionSort(int *a, int n) {
	for (int i = 1; i<n; ++i) {
		int key = a[i];                //contiene l'elemento dell'array corrente
		int j = i;
		while (j>0 && key<a[j - 1]) { //controlla se key sia minore dell'elemento precedente, se la condizione è verificata, gli elementi vengono scambiati
			a[j] = a[j - 1];          //l'elemento corrente viene scambiato con quello precedente
			--j;
		}
		a[j] = key;//ora a[j] è il nuovo key
	}
}
/*SCAMBIA*/
void scambia(int *c,int *b)//scambia due celle dell'array
{
    int temp;
    temp=*c;
    *c=*b;
    *b=temp;
}

/*insertion_sort tra p e q*/
void insertionSortMod(int *a, int p, int q){
	for (int i = p+1; i<q; ++i) {
		int key = a[i];
		int j = i;
		while (j>midp && key<a[j - 1]) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = key;
	}

}

/* MERGE SORT */

/*soluzione senza int max con unico array di supporto*/
void mergeIndex(int *a, int left, int mid, int right) { //unico array di supporto????
	int i,j;
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    for (i=0;i<n1;i++)
        L[i]=a[i];
    for (j=0;j<n2;j++)
        R[j]=a[i+j];

    i=0;j=0;
    int k;
    for(k=left;k<right;k++)
    {
        if (j==n2)//quando j è il massimo indice dell'array di dx, significa che siamo arrivati alla fine e quindi vengono salvati nell'array totale gli elementi dell'array di sx
        {
            for(k;k<right;k++)
            {
                a[k]=L[i];
            }
        }
        else     // oppure senza else qui ma con i++ tra riga 23 e 24
            if(L[i]<=R[j] && i!=n1)//controlla se l'elemento corrente dell'array di sinistra è <= dell'elemento corrente dell'array di dx ed inoltre che che non siamo arrivati alla fine dell'array
            {
                a[k]=L[i];
                if(j!=n2)//si entra in questa condizione quando R[j] <= L[i] ed inoltre si controla che l'array non sia terminato
                {
                    a[k]=R[j];
                    j++;
                }
    }

}


/*soluzione con int max*/
void mergeIntMax(int *a, int p, int q, int r) {
	int i,j;
    int n1=q-p+1;//sottrae l'indice centrale all'indice iniziale e somma uno
    int n2=r-q;//indice finale meno indice centrale 
    int L[n1+1],R[n2        else     // oppure senza else qui ma con i++ tra riga 23 e 24
	if(L[i]<=R[j] && i!=n1)//controlla se l'elemento corrente dell'array di sinistra è <= dell'elemento corrente dell'array di dx ed inoltre che che non siamo arrivati alla fine dell'array
	{
		a[k]=L[i];
		if(j!=n2)//si entra in questa condizione quando R[j] <= L[i] ed inoltre si controla che l'array non sia terminato
		{
			a[k]=R[j];
			j++;
		}
}

}


/*soluzione con int max*/
void mergeIntMax(int *a, int p, int q, int r) {
int i,j;
int n1=q-p+1;   //sottrae l'indice centrale all'indice iniziale e somma uno
int n2=r-q;     //indice finale meno indice centrale 
int L[n1+1],R[n2+1];//definisce le due sentinelle
for (i=0;i<n1;i++)
L[i]=a[i];     //L conterrà la prima parte dell'array ordinato 
for (j=0;j<n2;j++)
R[j]=a[i+j];   //R conterrà la seconda parte dell'array ordinato, l'indice i si somma a j per non sovrascrivere L

L[n1]= INT_MAX;//valori sentinella (relativo a L)
R[n2]= INT_MAX;//valori sentinella (relativo a R)

i=0;j=0;
int k;         //variabile di comodo, che assume il primo valore dell'array
for(k=p;k<r;k++)
{
if(L[i]<=R[j])//la condizione di if confronta se il primo elemento dell'array ordinato di sinistra sia minore o uguale all'array ordinato di destra
{
	a[k]=L[i];//in questo caso dentro all'array complessivo nella cella di a[k], verrà salvato il valore di L[i]
	i++;     //scorre l'indice e verifica l'elemento successivo
}			
else
{
	a[k]=R[j];//altrimenti mantiene il posto
	j++;
}
}
}

/*merge sort basata su mergeIndex*/
void mergeSortIndex(int *a, int p, int r) {
if (p<r)
{
int q= (p+r)/2 ;
mergeSortIndex(a,p,q);
mergeSortIndex(a,q+1,+1];//definisce le due sentinelle
    for (i=0;i<n1;i++)
        L[i]=a[i];		//L conterrà la prima parte dell'array ordinato 
    for (j=0;j<n2;j++)
        R[j]=a[i+j];	// r conterrà la seconda parte dell'array ordinato, l'indice i si somma a j per non sovrascrivere L

    L[n1]= INT_MAX;//valori sentinella (relativo a L)
    R[n2]= INT_MAX;//valori sentinella (relativo a R)
    
    i=0;j=0;
    int k;//variabile di comodo, che assume il primo valore dell'array
    for(k=p;k<r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];//la condizione di if confronta se il primo elemento dell'array ordinato di sinistra sia minore o uguale 
            i++;     //all'array ordinato di destra, in questo caso dentro all'array complessivo nella cella di a[k], verrà salvato il valore di L[i]
        }			//i++ per verificare l'elemento successivo
        else
        {
            a[k]=R[j];
            j++;
        }
    }
}

/*merge sort basata su mergeIndex*/
void mergeSortIndex(int *a, int p, int r) {
	if (p<r)
	{
		int q= (p+r)/2 ;
		mergeSortIndex(a,p,q);
		mergeSortIndex(a,q+1,p);
		mergeIndex(a,p,q,r);		
	}
}

/*merge sort basata su mergeIntMax*/
void mergeSortIntMax(int *a, int p, int r) {
	if (p<r)
	{
		int q= (p+r)/2 ;
		mergeSortIntMax(a,p,q);
		mergeSortIntMax(a,q+1,p);
		mergeIntMax(a,p,q,r);		
	}
}

/*soluzione ibrida: merge sort (usa mergeIntMax e insertionSort)*/
void hybridSortIntMax(int *a, int p, int r) {
	if((r-p) > 20)
		mergeSortIntMax(a,p,r);
	else
		insertionSort(a,r);
}

/*soluzione ibrida: merge sort (usa mergeSortIndex ed insertionSort)*/
void hybridSortIndex(int *a, int p, int r) {
	if((r-p) > 20)
		mergeSortIndex(a,p,r);
	else
		insertionSort(a,r);
}

/*merge in place*/
/* http://penguin.ewu.edu/cscd300/Topic/AdvSorting/MergeSorts/InPlace.html */
void mergeInPlace(int *a, int first, int mid, int last) {

}

/*merge sort usando mergeInPlace */
void inPlaceMergeSort(int *a, int p, int r) {

}


/* QUICK SORT */

/*suddivisione array*/
int standardPartition(int *a, int p, int r) {
	int x=a[r-1];//prendo ultimo valore array 
    int i = p-1; 
    for(int j=p;j<r-1;j++)
    {
        if (a[j]<=x) //se l'elemento corrente dell'array a è <= di x allora viene scambiato e messo nella parte sinistra dell'array 
        {
            i++;
            scambia(&a[i],&a[j]);
        }
                
    }
    i++;
    scambia(&a[i],&a[r-1]);         
return i;
}

/*quick sort base che usa standardPartition*/
void standardQuicksort(int *a, int p, int r) {
	if(p<r)
    {
        int q=standardPartition(a,p,r);
        standardQuicksort(a,p,q);       //  q e non q-1 come da pseudo-codice, perchè q mi serve come dim array
                                //  non come indice ultimo elemento se no salto di due in due.
        standardQuicksort(a,q+1,r);
    }
}

/*suddivisione array casuale*/
int randomizedPartition(int *a, int p, int r) {

}

/*quick sort che usa randomizedPartition*/
void randomizedQuicksort(int *a, int p, int r) {
}

void printProgressBar(double percentage) {					//farmela spiegare
	printf("[");
	int PBWIDTH = 70;
	int pos = PBWIDTH * percentage;
	int value = PBWIDTH - (int)(percentage*PBWIDTH);
	for (int i = 0; i < PBWIDTH; ++i) {
		if (i < pos)
			printf("=");
		else if (i == pos)
			printf(">");
		else
			printf(" ");
	}
	printf("] %d %%\r", (100 - value));
	fflush(stdout);
}

int main() {

	int seed; //salvare il seme per poter ripetere l'esperimento
	int indice_esperimento;
	int indice_ripetizione;
	int lunghezza_corrente = 0;

	double progress;

	clock_t inizio, fine, misurato;
	clock_t totale_insertion_sort = 0;
	clock_t totale_merge_sort_index = 0;
	clock_t totale_merge_sort_int_max = 0;
	clock_t totale_hybrid_sort_int_max = 0;
	clock_t totale_hybrid_sort_index = 0;
	clock_t totale_merge_sort_in_place = 0;
	clock_t totale_standard_quicksort = 0;
	clock_t totale_randomized_quicksort = 0;

	FILE *fp;

	int a[MAX_LUNGHEZZA];
	int temp[MAX_LUNGHEZZA];

	// per rendere l'esperimento ripetibile
	printf("Inserisci seme: ");
	scanf("%d", &seed);
	srand(seed);

	// gestione file dei tempi
	fp = fopen("tempi_ordinamento.txt", "w");
	if (fp == NULL) {
		perror("Errore apertura file");
		exit(EXIT_FAILURE);
	}

	printf("Inizio Esperimenti\n");

	for (indice_esperimento = 0; indice_esperimento<NUM_ESPERIMENTI; indice_esperimento++) {
		lunghezza_corrente += SALTO;
		CreaArray(a, lunghezza_corrente);
		CopiaArray(a, temp, lunghezza_corrente);

		//insertion sort
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			insertionSort(a,lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_insertion_sort = misurato;

		//merge sort int max
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			mergeSortIntMax(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_merge_sort_int_max = misurato;

		//merge sort index
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			mergeSortIndex(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_merge_sort_index = misurato;

		//hybrid sort int max
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			hybridSortIntMax(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_hybrid_sort_int_max = misurato;

		//hybrid sort index
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			hybridSortIndex(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_hybrid_sort_index = misurato;

		//merge in place
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			inPlaceMergeSort(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_merge_sort_in_place = misurato;

		//standard quicksort
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			standardQuicksort(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_standard_quicksort = misurato;

		//randomized quicksort
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			randomizedQuicksort(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_randomized_quicksort = misurato;

		fprintf(fp, "%d\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu \n", lunghezza_corrente, totale_insertion_sort,
			totale_merge_sort_int_max, totale_merge_sort_index, totale_hybrid_sort_int_max,
			totale_hybrid_sort_index, totale_merge_sort_in_place, totale_standard_quicksort, totale_randomized_quicksort);

		progress = (double)indice_esperimento / (NUM_ESPERIMENTI-1); //perchè -1??
		printProgressBar(progress);
	}

	fclose(fp);
	printf("Fine Esperimenti\n");
	return 0;
}
