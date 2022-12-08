#include<limits.h>
#include<stdio.h>
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
void insertionSortMod(int *b, int p, int q){
	for (int i = p+1; i<=q; ++i) {
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
    int a[11]={5,7,2,14,10,3,8,24,6,12,9};
	int b[11]={5,7,2,14,10,3,8,24,6,12,9};
	int i;
    insertionSort(a,11);
    for(i=0;i<11;i++)
	printf("%d ",a[i]);
	printf("\n\nInserire p e q\n");
    int p,q;
    scanf("%d%d",&p,&q);
    insertionSortMod(b,p,q);
    for(i=0;i<11;i++)
	printf("%d ",b[i]);
	printf("\n\n");
	
	
}