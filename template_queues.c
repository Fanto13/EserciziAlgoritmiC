#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define MAX_CODA 100001                // nelle nostre code ci sono sempre al massimo MAX_CODA elementi
#define NUM_ESPERIMENTI 200            // che si chiamano 0,1,...,MAX_CODA-1
#define SALTO 100
#define MAX_PRIORITA 1000


// ************************ MIN HEAPS ******* //

struct elemento_heap{
    int nome;
    int priorita;
};

typedef struct elemento_heap elemento_heap;

struct tipo_min_heap{
    int supporto[MAX_CODA];            // gli elementi che possono entrare nella si chiamano tutti da 0 a MAX_CODA-1
    elemento_heap heap[MAX_CODA];
    int heapsize;
};

typedef struct tipo_min_heap min_heap;


int left(int i) {                      // la differenza con lo pseudocodice è dovuta al fatto che in C gli array partono da 0
	return 2 * i +1;
}

int right(int i) {                     // la differenza con lo pseudocodice è dovuta al fatto che in C gli array partono da 0
	return 2 * i + 2;
}

int parent(int i){                     // la differenza con lo pseudocodice è dovuta al fatto che in C gli array partono da 0
    if (i==0) return 0;
    if ((i%2)==0) return i/2-1;
    return i/2;
}

void stampa_min_heap(min_heap h)
{
    for (int i=0; i<h.heapsize; i++) printf("sig. %d con priorita %d in posizione %d\n",h.heap[i].nome,h.heap[i].priorita,h.supporto[h.heap[i].nome]);
    printf("\n");
}

void inizializza_min_heap(min_heap *h,int num_elementi) // metto a caso le priorità, mantenendo la posizione
{
    h->heapsize=num_elementi;                           // come detto, in questo particolare esperimento la dimensione è fissa
    for (int i=0; i<num_elementi; i++)
    {
        h->heap[i].priorita=rand()%MAX_PRIORITA;
        h->heap[i].nome=i;
        h->supporto[h->heap[i].nome]=i;
    }
}

void min_heapify(min_heap *h,int i)    // faccio min_heapify su una posizione specifica della heap
{
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if ((l<=h->heapsize-1)&&(h->heap[l].priorita<h->heap[i].priorita)) smallest=l;
    if ((r<=h->heapsize-1)&&(h->heap[r].priorita<h->heap[smallest].priorita)) smallest=r;
    if (smallest==i) return;
    //scambio posizioni
    h->supporto[h->heap[i].nome]=smallest;
    h->supporto[h->heap[smallest].nome]=i;
    //scambio priorita
    elemento_heap temp_elem=h->heap[smallest];
    h->heap[smallest]=h->heap[i];
    h->heap[i]=temp_elem;
    min_heapify(h,smallest);
}

void build_min_heap(min_heap *h)
{

}

void decrease_key(min_heap *h,int nome,int new_priority)
{

}

int enqueue_min_heap(min_heap *h, elemento_heap nuovo_elemento)
{
    return 0;
}

elemento_heap extract_min_min_heap(min_heap *h)
{

}

// ************************ CODE SU ARRAY ******* //

struct elemento_coda_array{
    int priorita;
    int empty;
};

typedef struct elemento_coda_array elemento_coda_array;

struct tipo_coda_array{
    elemento_coda_array coda[MAX_CODA];            // gli elementi che possono entrare nella si chiamano tutti da 0 a MAX_CODA-1
    int size;
};

typedef struct tipo_coda_array coda_array;

void stampa_coda_array(coda_array q)
{
    for (int i=0; i<MAX_CODA; i++)
        if (q.coda[i].empty==0) printf("sig. %d con priorita %d\n",i,q.coda[i].priorita);
    printf("\n");
}

void inizializza_coda_array(coda_array *q,int num_elementi)
{
    q->size=num_elementi;                       // come detto, in questo particolare esperimento la dimensione è fissa
    for (int i=0; i<num_elementi; i++)
    {
        q->coda[i].empty=0;
        q->coda[i].priorita=rand()%MAX_PRIORITA;
    }
}

int enqueue_coda_array(coda_array *q,int nome,int priorita)
{

}

int extract_min_coda_array(coda_array *q,int num_elementi)
{

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


int main()
{
    int seed;
    FILE *fp;
	int indice_esperimento;
	int indice_ripetizione;
	int num_operazioni;
	clock_t inizio_h,fine_h;
    clock_t inizio_a,fine_a;

    min_heap h;                                 // riempiamo questa heap
    coda_array q;                               // e questa coda
    elemento_heap temp_elem_heap;
    int temp_elem_coda_array;

	// per rendere l'esperimento ripetibile
	printf("Inserisci seme: ");
	scanf("%d", &seed);
	srand(seed);

	fp = fopen("tempi_code.txt", "w");
	printf("Inizio Esperimenti\n");

    num_operazioni=0;
	for (indice_esperimento = 0; indice_esperimento<NUM_ESPERIMENTI; indice_esperimento++)
    {
		num_operazioni += SALTO;
		printf("\nFaccio %d operazioni",num_operazioni);
		inizializza_min_heap(&h,num_operazioni);
		build_min_heap(&h);
		inizializza_coda_array(&q,num_operazioni);
		inizio_h = clock();
		//*******************************CODA***************************
		for (int num_extract=0; num_extract<num_operazioni; num_extract++)
        {
            temp_elem_heap=extract_min_min_heap(&h);
            temp_elem_heap.priorita=rand()%MAX_PRIORITA;
            enqueue_min_heap(&h,temp_elem_heap);
        }
        fine_h = clock();
        inizio_a = clock();
		//*******************************CODA***************************
		for (int num_extract=0; num_extract<num_operazioni; num_extract++)
        {
            temp_elem_coda_array=extract_min_coda_array(&q,num_operazioni);
            enqueue_coda_array(&q,temp_elem_coda_array,rand()%MAX_PRIORITA);
        }
        fine_a = clock();
        fprintf(fp, "%d\t%d\t%d\n", num_operazioni, fine_h-inizio_h, fine_a-inizio_a);
    }
    printf("Fine Esperimenti\n");
	fclose(fp);
    return 0;
}

