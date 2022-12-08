#include<limits.h>
#include<stdio.h>
#include <time.h>

void scambia(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

   
    void CreaArray(int *a, int n) {//genera vettore casuale
        int i, n, seed;
        printf("Numero di elementi: ");
        scanf("%d", &n);
        printf("inserisci un seme:");
        scanf("%d", &seed);
        for (int i = 0; i < n; i++) {
            a[i] = rand() % (n * 10);;
        }
    }

void SelectionSort(int *a, int n) {
    int i,j;
    for (i = 0; i<n-1; ++i) {
		int key = i;
        for (j = i+1; j<n; ++j)
            if(a[j]<a[key])
                key=i;
        scambia(&a[key],&a[j]);
	}
}

int dim=11;
int main(){
    CreaArray(dim);
    SelectionSort(a,dim);
    
    for(int i=0;i<dim;i++){
	    printf("%d ",a[i]);}
	
	printf("\n\n");
	
}//chiude il main