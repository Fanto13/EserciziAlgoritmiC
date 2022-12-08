#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

///STRUCTS
typedef struct node_s
{
	int key;
	struct node_s *next;
}node;

typedef struct hash_table_s
{
	int size;
	node **table;
}hash_table;

///FUNCTIONS
unsigned int Hashing(int key);
void List(int key);
int Initialize(int size);
node *Search(int key);
int Insert(int key);
int Delete(int key);
int Destroy();

void WriteFile(char *filename, double Alpha, int num_op, double ttime);

///GLOBAL VARIABLES
hash_table *hash;
int HASH_SIZE = 761;

///MAIN

void main()
{
	int check; 
	int num_op = 1000;
	int max_op = 300000;
	int op;
	int i;
	int key;
	time_t t;
	clock_t start, end;
	double ttime = 0;
	
	srand((unsigned) time(&t));
	
	//printf("check = %d and size %d\n", check, hash->size);
																								
	while(num_op<max_op)
	{
		Initialize(HASH_SIZE);
		printf("num_op: %d\n", num_op);
		ttime = 0;
		
		start = clock();
		for(i = 0;i<num_op;i++)
		{
			
			op = rand()%4+1;
			
			key = rand();
		
			
			if(op<4)
				Insert(key);
			else if(op == 4)
				Delete(key);
				
			
		}
		end = clock();

		ttime = (double)(end-start)/CLOCKS_PER_SEC;
		//printf("Time taken for %d operations: %.2f\n", num_op, ttime);
		WriteFile("list.txt",(num_op/HASH_SIZE), num_op, ttime);
		//List(Hashing(value));
		Destroy();

		num_op += 1000;
	}
}

///FUNCTIONS

unsigned int Hashing(int key)
{
	return key%hash->size;
}

int Initialize(int size)
{
	int i;
	
	if(size < 1)
		return 2;
		
	if((hash = malloc(sizeof(hash_table))) == NULL)
		return 1;
		
	if( (hash->table = malloc(sizeof(node) *size) ) == NULL)
		return 1;
		
	for(i = 0;i<size;i++)
	{
		hash->table[i] = NULL;
	}
	
	hash->size = size;
	
	return 0;
}

node *Search(int key)
{
	node *found;
	
	unsigned int hval = Hashing(key);
	
	found = hash->table[hval];
	
	if(found == NULL)
		return NULL;
		
	while(found != NULL && found->key != key)
		found = found->next;
		
	return found;
}

int Insert(int key)
{
	node *found;
	node *new_node;
	
	found = Search(key);
	
	unsigned int hval = Hashing(key);
	
	if(found != NULL)
		return 2;
		
	if((new_node = malloc(sizeof( node)) ) == NULL)
		return 2;
		
	new_node->key = key;
	
	new_node->next = hash->table[hval];
	
	hash->table[hval] = new_node;
	
	return 0;
}

int Delete(int key)
{
	node *found;
	node *current;
	node *previous = NULL;
	
	found = Search(key);
	
	if(found == NULL)
		return 1;
		
	unsigned int hval = Hashing(key);
	
	current = hash->table[hval];
	
	//Se il primo della lista e lista vuota
	if((current->key == key) && (current->next == NULL))
	{
		hash->table[hval] = NULL;
		free(current);
		return 0;
	} //Se primo della lista e lista non vuota
	else if((current->key == key) && (current->next != NULL))
	{
		//printf("%d first not last\n", current->key);
		hash->table[hval] = current->next;
		current = NULL;
		free(current);
		return 0;
	}
	
	previous = current;
	current = current->next;
	
	for(current;current != NULL; current = current->next)
	{
		if(current->key == key)
		{
			//printf("%d found\n", current->key);
			//printf("%d previous is\n", previous->key);
			
			previous->next = current->next;
			current = NULL;
			free(current);
			return 0;
		}
		previous = current;
		//printf("%d current\n", current->key);
		//printf("%d previous\n", previous->key);
	}
	
	return 2;
}

void List(int key)
{
	unsigned int hval = Hashing(key);
	
	node *nodo = hash->table[hval];
	
	if(nodo == NULL)
	{
		printf("nothing in here..\n");
		return;
	}
	
	while(nodo != NULL)
	{
		printf("%d->", nodo->key);
		nodo = nodo->next;
	}
	printf("NULL\n");
}

int Destroy()
{
	int i;
	node *nodo;
	node *temp;
	
	if(hash == NULL)
		return 2;

	for(i = 0;i<hash->size;i++)
	{

		nodo = hash->table[i];

		while(nodo != NULL)
		{
			temp = nodo;
			nodo = nodo->next;
			//printf("deleting %d key\n", temp->key);

			free(temp);
		}
	}
	
	free(hash->table);
	free(hash);
	
	return 0;
}

void WriteFile(char *filename, double Alpha, int num_op, double ttime)
{
	FILE *fp;
	
	fp = fopen(filename, "a+");
		fprintf(fp,"%.2f;%d;%.2f\n", Alpha, num_op, ttime);
	fclose(fp);
}
