//define che serve per poter usare la vecchia scanf
//con visual studio 2015
//#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_LUNGHEZZA 50000
#define NUM_ESPERIMENTI 100
#define REP_PER_ESPERIMENTO 10
#define SALTO 500

/*Nota: SALTO*NUM_ESPERIMENTI deve essere <= MAX_LUNGHEZZA */

#define K 51 //parametro per la hybrid sort

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
/* SCAMBIA DUE ELEMENTI DELL'ARRAY n */
void Scambia(int *c,int *b)
{
    int temp;
    temp=*c;
    *c=*b;
    *b=temp;
}
/*************************************/

/*************************************/
/* INSERTION SORT */
void Insertion_Sort(int *a, int n) {
	for (int i = 1; i<n; ++i) {
		int key = a[i];
		int j = i;
		while (j>0 && key<a[j - 1]) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = key;
	}
}

/*insertion_sort tra p e q*/
void Insertion_SortMod(int *a, int p, int q){
	for (int i = p+1; i<q; ++i) {
		int key = a[i];
		int j = i;
		while (j>p && key<a[j - 1]) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = key;
	}
}
/* MERGE SORT */

/*soluzione senza int max con unico array di supporto*/
void MergeIndex(int *A, int left_index, int middle_index, int right_index) {
    int n1=middle_index - left_index +1;  //Dimensione array di sinistra
    int n2=right_index - middle_index;    //Dimensione array di destra
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
        {
            A[k]=R[j];
            k++;
        }
    }
    else
        if (j==n2)
        {
            for(i;i<n1;i++)
            {
                A[k]=L[i];
                k++;
            }
        }
}

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

/*merge sort basata su mergeIndex*/

  void MergeIndex_Sort(int *A, int left_index, int right_index) {
      if (left_index < right_index) //rompo array fino ad arrivare a casella unitaria
      {
          int middle_index= (left_index + right_index) / 2 ;
          MergeIndex_Sort(A,left_index,middle_index);  //ordinamento su nuova parte dx
          MergeIndex_Sort(A,middle_index+1 , right_index); //ordinamento su nuova parte sx
          MergeIndex(A,left_index,middle_index,right_index); //inserimento ordinato delle due parti relative
                                                                //alla n-esima chiamata ricorsiva
      }
  }

/*merge sort basata su Random_Quick_Sort_Sort*/

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

/*soluzione ibrida: merge sort (usa Random_Quick_Sort_Sort e insertionSort)*/
void hybridSortIntMax(int *a, int left_index, int right_index) {
	if (right_index - left_index > K)
	{
		int middle_index= (left_index + right_index) / 2 ;
		hybridSortIntMax(a,left_index,middle_index);
		hybridSortIntMax(a,middle_index+1,right_index);
		Merge_Int_Max_Sort(a,left_index,right_index);
	}
	else{
		Insertion_SortMod(a,left_index,right_index);
	}
}

/*soluzione ibrida: merge sort (usa mergeSortIndex ed insertionSort)*/
void hybridSortIndex(int *a, int left_index, int right_index) {
	if (right_index - left_index > K)
	{
		int middle_index= (left_index + right_index) / 2 ;
		hybridSortIndex(a,left_index,middle_index);
		hybridSortIndex(a,middle_index+1,right_index);
		MergeIndex_Sort(a,left_index,right_index);
	}
	else{
		Insertion_SortMod(a,left_index,right_index);
	}
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
        Standard_Quick_Sort(a,left_index,compare_index);	// Applico Standar_Quick_Sort su insieme sx
        Standard_Quick_Sort(a,compare_index+1,dimensione);	// Applico Standar_Quick_Sort su insieme dx
    }
}

/*suddivisione array casuale*/
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

void printProgressBar(double percentage) {
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
	clock_t totale_Random_quicksort = 0;
	clock_t totale_Standard_quicksort = 0;

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
			Insertion_Sort(a,lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_insertion_sort = misurato;

		//merge sort int max
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			Merge_Int_Max_Sort(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_merge_sort_int_max = misurato;

		//merge sort index
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			MergeIndex_Sort(a, 0, lunghezza_corrente);
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
			Standard_Quick_Sort(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_Standard_quicksort = misurato;



		//Random quicksort
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			Random_Quick_Sort(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_Random_quicksort = misurato;

		fprintf(fp, "%d\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu \n", lunghezza_corrente, totale_insertion_sort,
			totale_merge_sort_int_max, totale_merge_sort_index, totale_hybrid_sort_int_max,
			totale_hybrid_sort_index, totale_merge_sort_in_place, totale_Standard_quicksort, totale_Random_quicksort);

		progress = (double)indice_esperimento / (NUM_ESPERIMENTI-1);
		printProgressBar(progress);
	}

	fclose(fp);
	printf("Fine Esperimenti\n");
	return 0;
}
