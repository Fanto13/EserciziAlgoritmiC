//define che serve per poter usare la vecchia scanf
//con visual studio 2015
//#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_LUNGHEZZA 1001
#define NUM_ESPERIMENTI 1000//con quale granularità si passa da un numero di elementi a quella successiva
#define REP_PER_ESPERIMENTO 100
#define SALTO 100//con quale granularità si passa da un numero di elementi a quella successiva

/*Nota: SALTO*NUM_ESPERIMENTI deve essere <= MAX_LUNGHEZZA */

#define K 10 //parametro per la hybrid sort

//creazione di array di int ed element casuali di lunghezza n
void CreaArray(int *a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (n * 10);;
	}
}
//eseguire insertion sort, tante volte quanto è indicato, per sapere quanto tempo è passato basta fare tempo fine - tempo inizio

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
void insertionSortMod(int *a, int p, int q){
	for (int i = p+1; i<=q; ++i) {
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
void mergeIndex(int *a, int left, int mid, int right) {


}

/*soluzione con int max*/
void mergeIntMax(int *a, int p, int q, int r) {
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1], R[n2+2];
		for(i=1;i<n1;i++){
			L[i]=A[p+i-1];
		}
		for(j=1;j<n2;j++){
			L[j]=A[p+j-1];
		}
		L[n1+1]=INT_MAX;
		R[n2+1]=INT_MAX;
		i=0;
		j=0;

		int(k=p;k<r,k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i=i++;
		}
		else A[k]=R[j];
		j=j++;
}

/*merge sort basata su mergeIndex*/
void mergeSortIndex(int *a, int p, int r) {

}

/*merge sort basata su mergeIntMax*/
void mergeSortIntMax(int *a, int p, int r) {

}

/*soluzione ibrida: merge sort (usa mergeIntMax e insertionSort)*/
void hybridSortIntMax(int *a, int p, int r) {

}

/*soluzione ibrida: merge sort (usa mergeSortIndex ed insertionSort)*/
void hybridSortIndex(int *a, int p, int r) {

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

}

/*quick sort base che usa standardPartition*/
void standardQuicksort(int *a, int p, int r) {

}

/*suddivisione array casuale*/
int randomizedPartition(int *a, int p, int r) {

}

/*quick sort che usa randomizedPartition*/
void randomizedQuicksort(int *a, int p, int r) {
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

	double progress;//progress bar 

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
		totale_insertion_sort += misurato;

		//merge sort int max
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			mergeSortIntMax(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_merge_sort_int_max += misurato;

		//merge sort index
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			mergeSortIndex(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_merge_sort_index += misurato;

		//hybrid sort int max
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			hybridSortIntMax(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_hybrid_sort_int_max += misurato;

		//hybrid sort index
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			hybridSortIndex(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_hybrid_sort_index += misurato;

		//merge in place
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			inPlaceMergeSort(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_merge_sort_in_place += misurato;

		//standard quicksort
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			standardQuicksort(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_standard_quicksort += misurato;

		//randomized quicksort
		inizio = clock();
		for (indice_ripetizione = 0; indice_ripetizione<REP_PER_ESPERIMENTO; indice_ripetizione++) {
			randomizedQuicksort(a, 0, lunghezza_corrente);
			CopiaArray(temp, a, lunghezza_corrente);
		}
		fine = clock();
		misurato = fine - inizio;
		totale_randomized_quicksort += misurato;

		fprintf(fp, "%d\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu \n", lunghezza_corrente, totale_insertion_sort,
			totale_merge_sort_int_max, totale_merge_sort_index, totale_hybrid_sort_int_max,
			totale_hybrid_sort_index, totale_merge_sort_in_place, totale_standard_quicksort, totale_randomized_quicksort);

		progress = (double)indice_esperimento / (NUM_ESPERIMENTI-1);
		printProgressBar(progress);
	}

	fclose(fp);
	printf("Fine Esperimenti\n");
	return 0;
}
