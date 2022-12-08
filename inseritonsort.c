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
void insertionSortMod(int *a, int p, int q){
	for (int i = p+1; i<=q; ++i) {
		int key = a[i];
		int j = i;
		while (j>p && key<a[j - 1]) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = key;
	}

}


int main(){
    int a[11]={5,7,2,14,10,3,8,24,6,12,9};
    int i;
    /*insertionSort(a,7);
    for(i=0;i<7;i++)
    printf("%d ",a[i]);*/
    int p,q;
    scanf("%d%d",&p,&q);
    insertionSortMod(a,p,q);
    for(i=0;i<11;i++)
    printf("%d ",a[i]);
}