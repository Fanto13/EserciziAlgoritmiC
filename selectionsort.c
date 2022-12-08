#include<limits.h>
#include<stdio.h>
#include<time.h>
#define N 11

void SelectionSort(int a[], int N) {
	int i, j, min; 
	int t;
  
	for (j=0; j < N-1; j++) {
	  min = j;
	  for (i= j+1; i < N; i++) {
      if (a[j] < a[min]) {
      min = i;
      }
      }
      t = a[min];
      a[min] = a[i];
      a[i] = t;
    	}//chiude il primo for
  }

  int generavettore(int x[]) {  //genera vettore casuale
    (unsigned)time(NULL)   int i, n;
    printf("Numero di elementi: ");
    scanf("%d", &n);
    srand((unsigned)time(NULL));
    for (i=0; i<n; i++) {
      x[i] = rand() % 100;
    }
    return(n);
  }


int main(){
   int x[N];
   generavettore(N);
   SelectionSort(a,N);
    int i;
    for (i=0; i<n; i++) {
      printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
  }
	
    


    
