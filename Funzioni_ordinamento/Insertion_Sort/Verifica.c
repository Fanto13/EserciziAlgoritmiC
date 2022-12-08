/*
La funzione crea array sempre più disordinati a partire da un array ordinato
Li ordina con la funzione e controlla se sono veramente ordinati
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include"Verifica.h"

void Crea_Array(void){
  for(int i=0;i<DIMENSIONE;i++)
  {
    A[i]=rand()%1000;
  }
  for(int i=DIMENSIONE-1;i>=0;i--)
  {
    B[i]=i;
  }
}

void Stampa(){
  for(int i=0;i<DIMENSIONE;i++)
    {
      printf("%d ",A[i]);
    }
  printf("\n\n" );
  for(int i=0;i<DIMENSIONE;i++)
    {
      printf("%d ",B[i]);
    }

}
/*void Copia_Array(int *A, int *B, int n) {
	for (int i = 0; i<DIMENSIONE; i++)
    B[i] = A[i];
}



void Scambia(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

void Disordina_Array(int *A, int dimensione){
  int x=rand() % dimensione; //printf("%d\t",x);
  int y=rand() % dimensione; //printf("%d\n\n",y);
  Scambia (&A[x],&A[y]);
}
*/
int Verifica_Ordine_Array(int *A,int dimensione){
  int ordinato=1;
  for(int i=0;i<dimensione-1;i++)
    if (A[i]>A[i+1])
    {
      ordinato=0;
    }
  return ordinato;
}
int Verifica_Ordine_ArrayMod(int *A,int left_index,int right_index){
  int ordinato=1;
  for(int i=left_index;i<right_index-1;i++)
    if (A[i]>A[i+1])
    {
      ordinato=0;
    }
  return ordinato;
}
void PrintProgressBar(double percentage) {
	printf("[");
	int PBWIDTH = 70;
	int pos = PBWIDTH * percentage/100;                   //diviso 10 perchè ho moltiplicato per 10 nel main
	int value = PBWIDTH - (int)(percentage*PBWIDTH)/100;  //diviso 10 perchè ho moltiplicato per 10 nel main
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

void Verifica()
{
  int ordinatoA=Verifica_Ordine_Array(A,DIMENSIONE);
  int ordinatoB=Verifica_Ordine_Array(B,DIMENSIONE);
  if(!ordinatoA || !ordinatoB)
  {
    printf("\nERRORE !!!\n\n");
  }
  else
  {
    printf("\nORDINATO!!!\n\n");
  }
}
void VerificaMod(int left_index, int right_index)
{
  int ordinatoA=Verifica_Ordine_ArrayMod(A,left_index,right_index);
  int ordinatoB=Verifica_Ordine_ArrayMod(B,left_index,right_index);
  if(!ordinatoA || !ordinatoB)
  {
    printf("\nERRORE !!!\n\n");
  }
  else
  {
    printf("\nORDINATO!!!\n\n");
  }
}