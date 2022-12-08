#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//variabili globali
#define NP 701
#define OPERAZIONI 1000000

//struttura del nodo della lista
typedef struct nodo {
	//chiave (informazione contenuta nel nodo)
	int key;
	//puntatore al nodo precedente
	struct nodo *prev;
	//puntatore al nodo successivo
	struct nodo *next;
} t_nodo;

//struttura della lista
typedef struct lista {
	//puntatore alla testa della lista
	struct nodo *head;
} t_lista;

//dichiarazione globale della tabella HASH
typedef t_lista *hash_t;
hash_t H;

//funzione per inizializzare la lista
void init_list(t_lista *L) {
	//la testa della lista inizialmente punta a NULL
	L->head = NULL;
}

/*
//funzione per stampare la lista
void print_list(t_lista *L) {
	t_nodo *tmp;
	tmp = L->head;
	int i;

	if(tmp==NULL) {
		printf("Lista vuota\n");
	}
	else {
		for(i=1;i<=L->cardinalità;i++) {
			printf("nodo %d: %d\n", i, tmp->key);
			tmp = tmp->next;
		}
	}
}
*/

//funzione per inserire un nodo nella lista
void Insert(t_lista *L, int val) {
	//creazione del nuovo nodo e allocazione di uno spazio in memoria
	t_nodo *x;
	x = malloc(sizeof(t_nodo));
	//inizializzo il nuovo nodo e gli inserisco il nuovo dato
	x->key=val;

	x->next=L->head;
	//se la lista presenta dei nodi
	if(L->head!=NULL) {
		L->head->prev=x;
	}
		
	L->head=x;
	x->prev=NULL;
}

//funzione per cercare un nodo nella lista
t_nodo *Search(t_lista *L, int val) {
	t_nodo *tmp;
	tmp = L->head;
	/*scorro la lista cercando il val passato e ritorno l'indirizzo del 
	primo nodo che contiene val, altrimenti continuo a scorrere tutta la 
	lista*/
	while((tmp!=NULL) && (tmp->key!=val)) {
		tmp = tmp->next;
	}

return tmp;
}

//funzione per cancellare un nodo dalla lista
void Delete(t_lista *L, t_nodo *del) {
	//sgancio il nodo puntato da del dalla lista
	if(del->prev!=NULL) {
		del->prev->next = del->next;
	}
	else {
		L->head = del->next;
	}

	if(del->next!=NULL) {
		del->next->prev = del->prev;
	}

	//libero la memoria allocata dal nodo
	free(del);
}

//funzione di hashing
int hashing_func(int key) {
	int ret=0;
	ret=key%NP;

return ret;
}

//funzione per la creazione della tabella HASH
void crea_hash() {
	int i;
	H = (hash_t) malloc (NP*sizeof(t_lista));
	for(i=0;i<NP;i++) {
		t_lista L;
		init_list(&L);
		H[i] = L;
	}
}

//funzione per la ricerca di un elemento nella tabella HASH
t_nodo *search_hash(int value) {
	int key_value = hashing_func(value);
	t_nodo *cerca = Search(&H[key_value], value);
	/*
	//vedo se il valore è presente nella tabella hash
	if(cerca == NULL) {
		printf("Non ho trovato alcun valore nella tabella hash\n");
	}
	else {
		printf("Ho trovato il valore: %d\n", cerca->key);
	}
	*/
return cerca;
}

//funzione per l'inserimento di un elemento nella tabella HASH
void inserisci_hash(int value) {
	int key_value = hashing_func(value);
	t_nodo *cerca = search_hash(value);
	if(cerca == NULL) {
		Insert(&H[key_value], value);
	}
	/*
		//verifico se il valore è stato inserito
		//printf("Stampo la lista relativa alla cella %d della tabella hash:\n", key_value);
		//print_list(&H[key_value]);
	}
	else {
		printf("Valore già presente\n");
	}
	*/
}

//funzione per l'eliminazione di un elemento dalla tabella HASH
void delete_hash(int value) {
	int key_value = hashing_func(value);
	t_nodo *cerca = search_hash(value);
	if(cerca != NULL) {
		Delete(&H[key_value], cerca);
	}	
	/*
		//verifico se il valore è stato eliminato
		//printf("Stampo nuovamente la lista:\n");
		//print_list(&H[key_value]);
		//printf("Cancellato\n");
	}
	else {
		printf("Non esiste\n");
	}
	*/
}

void print_hash(){
  int i;
  t_nodo *x;
  for(i=0;i<NP;i++){
    x = H[i].head; 
    printf("\n[%d]-> ",i);
    while(x != NULL){
      printf("%d ",x->key);
      x = x->next;
    }
  }
}

//funzione per liberare la tabella HASH
void free_hash() {
	int i;

	for(i=0;i<NP;i++) {
		
		while(H[i].head != NULL) {
			t_nodo *prox = H[i].head->next;
			free(H[i].head);
			H[i].head = prox;
		}

	}
}

int main() {

	int value, i, l, probability, iterazioni=10000;
	clock_t start_t=0, end_t=0;
	double total_t=0, media;
	FILE *fp;
	fp = fopen("Graph_List.txt", "w");
	fprintf(fp,"Operazione\t\tTempo Lista\n");

	srand((unsigned)time(NULL));

	crea_hash();

	while(iterazioni<OPERAZIONI) {
		start_t = clock();
		for(i=1;i<iterazioni;i++) {
			//scelgo il valore
			value = rand();
			//definisco la probabilità privilegiando l'operazione di inserimento
			probability = rand()%5;
			
			if(probability<4) {
				inserisci_hash(value);
			}
			else {
				delete_hash(value);
			}
		}
		end_t = clock();
		total_t += (double)(end_t-start_t);
		media = (total_t/CLOCKS_PER_SEC);
		fprintf(fp,"%d\t\t%f\n",i,media);
		
		iterazioni += 10000;
		free_hash();
	}	
	
	fclose(fp);

return 0;
}