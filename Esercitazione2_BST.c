#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//variabili globali
#define NP 701
#define OPERAZIONI 1000000


//struttura del nodo dell'albero
typedef struct nodo {
	//chiave (informazione contenuta nel nodo)
	int key;
	//puntatore al padre
	struct nodo *p;
	//puntatore al figlio sinistro
	struct nodo *left;
	//puntatore al figlio destro
	struct nodo *right;
} t_nodo;

//struttura del BST
typedef struct BST {
	int cardinalità;
	//puntatore alla radice
	struct nodo *root;
} t_BST;

//dichiarazione globale della tabella HASH
typedef t_BST *hash_t;
hash_t H;
//t_BST *H;
//funzione per inizializzare il BST
void init_BST(t_BST *T) {
	T->cardinalità=0;
	//la radice del BST inizialmente punta a NULL
	T->root = NULL;
}

//funzione per verificare che il BST sia corretto
void InOrderTreeWalk(t_nodo *x) {
	if(x != NULL) {
		InOrderTreeWalk(x->left);
		printf("%d\n", x->key);
		InOrderTreeWalk(x->right);
	}
}

//funzione per inserire un nodo nel BST
void TreeInsert(t_BST *T, int val) {
	//creazione del nuovo nodo e allocazione di uno spazio in memoria
	t_nodo *z;
	z = malloc(sizeof(t_nodo));
	//inizializzo il nuovo nodo e gli inserisco il nuovo dato
	z->key=val;
	z->left=NULL;
	z->right=NULL;
	
	//tengo traccia del padre del nodo analizzato (x)
	t_nodo *y = NULL;
	t_nodo *x = T->root;

	/* si va nella parte sinistra dell'albero o nella parte destra per inserire il nodo */
	while(x!=NULL) {
		y=x;
		if(z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	//si aggiorna il puntatore al padre quando ha trovato la posizione corretta
	z->p=y;
	//caso di albero vuoto
	if(y==NULL) {
		T->root=z;
	}
	if((y!=NULL) && (z->key < y->key)) {
		y->left = z;
	}
	if((y!=NULL) && (z->key >= y->key)) {
		y->right = z;
	}

	T->cardinalità++;
}

//funzione per cercare un nodo nel BST
//TreeSearch iterativo
t_nodo *TreeSearch(t_BST *T, int val) {
	t_nodo *tmp;
	tmp = T->root;

	while((tmp != NULL) && (val != tmp->key)) {
		if(val < tmp->key) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}

return tmp;
}

//fuzione per il trapianto (necessaria per la funzione Delete)
void Transplant(t_BST *T, t_nodo *u, t_nodo *v) {
	if(u->p == NULL) {
		T->root = v;
	}
	if((u->p!=NULL) && (u == u->p->left)) {
		u->p->left = v;
	}
	if((u->p!=NULL) && (u == u->p->right)) {
		u->p->right = v;
	}
	if(v!=NULL) {
		v->p = u->p;
	}
}

//funzione che trova il minimo (necessaria per determinare il successore)
t_nodo *TreeMinimum(t_nodo *min) {
	while(min->left!=NULL) {
		min=min->left;
	}
return min;
}

//funzione per cancellare un nodo dal BST
void TreeDelete(t_BST *T, t_nodo *del) {
	//se il nodo da eliminare non ha figli sinistri
	if(del->left == NULL) {
		//si trapianta il sotto-albero destro del nodo da eliminare al posto del nodo stesso
		Transplant(T,del,del->right);
	}
	//se il nodo da eliminare ha il figlio sinistro ma non quello destro
	if((del->left!=NULL) && (del->right == NULL)) {
		//si trapianta il sotto-albero sinistro del nodo da eliminare al posto del nodo stesso
		Transplant(T,del,del->left);
	}
	//caso di nodo con due figli
	if((del->left!=NULL) && (del->right!=NULL)) {
		/* se il nodo da eliminare ha due figli si prende il successore immediato di y,
		che si trova nel sotto-albero destro del nodo da eliminare e non ha figli sinistri.
		Il nodo y prende il posto del nodo da eliminare */
		t_nodo *y = TreeMinimum(del->right);
		//se y è figlio immediato del nodo da eliminare
		if(y->p!=del) {
		//il nodo stesso diventa il figlio destro di y, il resto rimane invariato
			Transplant(T,y,y->right);
			y->right = del->right;
			y->right->p = y;
		}
		/* altrimenti (y è nel sotto-albero destro ma non è figlio immediato)
		si rimpiazza y con il suo figlio destro e poi si rimpiazza il nodo da eliminare
		con y */
		Transplant(T,del,y);
		y->left = del->left;
		y->left->p = y;
	}

	//libero la memoria allocata dal nodo che è stato eliminato
	free(del);
	T->cardinalità--;
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
	H = (t_BST *) malloc (NP*sizeof(t_BST));
	for(i=0;i<NP;i++) {
		//H[i].root = NULL;
		t_BST T;
		init_BST(&T);
		H[i] = T;
	}
}

//funzione per la ricerca di un elemento nella tabella HASH
t_nodo *search_hash(int value) {
	int key_value = hashing_func(value);
	t_nodo *cerca = TreeSearch(&H[key_value], value);
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
		TreeInsert(&H[key_value], value);
	}
	/*
		//verifico se il valore è stato inserito
		//printf("Stampo l'albero relativo alla cella %d della tabella hash:\n", key_value);
		//la funzione si aspetta un puntatore ad un nodo e gli passiamo il puntatore alla radice
		//InOrderTreeWalk(H[key_value].root);
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
		TreeDelete(&H[key_value], cerca);
	}
	/*
		//verifico se il valore è stato eliminato
		//printf("Stampo nuovamente l'albero:\n");
		//InOrderTreeWalk(H[key_value].root);
	}
	else {
		printf("Non esiste\n");
	}*/
}


void free_BST(t_nodo *nodel) {
	if(nodel == NULL) {
		return;
	}
	else {
		t_nodo *left = nodel->left;
		t_nodo *right = nodel->right;
		free(nodel);
		free_BST(left);
		free_BST(right);
	}
}

//funzione per liberare la tabella HASH
void free_hash() {
	int i;


	//printf("valore: %d\n", H[i].root->key);

	for(i=0;i<NP;i++) {
		free_BST(H[i].root);
		H[i].root = NULL;
	}
}

void print_hash(){
  int i, cont;
  t_nodo *x;


  for(i=0;i<NP;i++){

  	cont = H[i].cardinalità;
  	printf("%d\n", cont);
    /*x = H[i].root; 
    printf("\n[%d]-> ",i);
    if(x != NULL){
		InOrderTreeWalk(x);
    }*/
  }

}


int main() {

	int value, i, l, probability, iterazioni=10000;
	clock_t start_t=0, end_t=0;
	double total_t=0, media;
	FILE *fp;
	fp = fopen("Graph_BST.txt", "w");
	fprintf(fp,"Operazione\t\tTempo BST\n");
 
	srand((unsigned)time(NULL));


	crea_hash();
/*
	for(i=0;i<100;i++) {
		value = rand();
		inserisci_hash(value);
	}

	print_hash();
*/

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

	/*
	//ciclo che aumenta le operazioni
	for(i=1000;i<OPERAZIONI;i+=1000)
	{
		//scelgo il valore
		value = rand();
		//definisco la probabilità privilegiando l'operazione di inserimento
		probability = rand()%5;
		start_t = clock();
			
			if(probability<4) {
				inserisci_hash(value);
			}
			else {
				delete_hash(value);
			}

		end_t = clock();
		total_t += (double)(end_t-start_t);
		media = (total_t/CLOCKS_PER_SEC);
		fprintf(fp,"%d\t\t%f\n",i,media);

		//libero la tabella HASH
		free_hash();	
	}*/

	fclose(fp);

return 0;
}