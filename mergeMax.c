#include<limits.h>
#include<stdio.h>

/*soluzione con int max*/
void mergeIntMax(int *a, int p, int q, int r) {
    int i,j;
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    for (i=0;i<n1;i++)
        L[i]=a[i];
    for (j=0;j<n2;j++)
        R[j]=a[i+j];

    L[n1]= INT_MAX;
    R[n2]= INT_MAX;
    
    i=0;j=0;
    int k;
    for(k=p;k<r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
    }

}

int main(){
    int a[11]={2,5,7,20,30,3,6,9,25,50,52};
    int i;
    mergeIntMax(a,0,4,10);
     for(i=0;i<11;i++)
        printf("%d ",a[i]);
}