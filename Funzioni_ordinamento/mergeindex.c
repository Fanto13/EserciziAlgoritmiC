#include<limits.h>
#include<stdio.h>

/*soluzione con int max*/
void mergeIntMax(int *a, int p, int q, int r) {
    int i,j;
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],R[n2];
     for (i=0;i<n1;i++)
        L[i]=a[i];//differenza rispetto allo pseudocodice
     for (j=0;j<n2;j++)
        R[j]=a[i+j];

    i=0;j=0;
    int k;
    for(k=p;k<r;k++)
    {
        if (j==n2)
        {
            for(k;k<r;k++)
            {
                a[k]=L[i];
            }
        }
        else     // oppure senza else qui ma con i++ tra riga 23 e 24
            if(L[i]<=R[j] && i!=n1)
            {
                a[k]=L[i];
                i++;
            }
            else
                if(j!=n2)
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