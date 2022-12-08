#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>



int generavettore(int x[]) {  //genera vettore casuale
    int i, n;
    printf("Numero di elementi del vettore: ");
    scanf("%d", &n);
    srand((unsigned)time(NULL));
     for (i=0; i<n; i++) {
         x[i] = srand(seed);
    }
    return(n);
  }

  void scambia(int *a,int *b)
  {
      int temp=*a;
      *a=*b;
      *b=temp;
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


int main(){
    int dim=11;
    int a[dim];
    int seed;
    // per rendere l'esperimento ripetibile
	printf("Inserisci seme: ");
	scanf("%d", &seed);
	
    generavettore(a);
    SelectionSort(a,dim);
    
    for(int i=0;i<dim;i++)
	    printf("%d ",a[i]);
	
	printf("\n\n");
	
}