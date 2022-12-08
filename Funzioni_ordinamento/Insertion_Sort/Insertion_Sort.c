#include<limits.h>
#include<stdio.h>
#include"Verifica.h"
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


void Insertion_SortMod(int *b, int p, int q){
	for (int i = p+1; i<q; ++i) {
		int key = b[i];
		int j = i;
		while (j>p && key<b[j - 1]) {
			b[j] = b[j - 1];
			--j;
		}
		b[j] = key;
	}
}




int main(){
	printf("Insertion_Sort --> 1\nInsertion_SortMod --> 2\nScelta: ");
	int scelta;
	scanf("%d",&scelta);
	if (scelta==1)
	{
		Crea_Array();
		Insertion_Sort(A,DIMENSIONE);
		Insertion_Sort(B,DIMENSIONE);
		Verifica();
	}
	else
	{	
		int a=10,b=20;
		Crea_Array();
		Insertion_SortMod(A,a,b);
		Insertion_SortMod(B,a,b);
		VerificaMod(a,b);
	}
	
	Stampa();
}
