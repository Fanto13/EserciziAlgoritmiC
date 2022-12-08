#include<stdio.h>
#include<stdlib.h>

void scambia(int *c,int *b)
{
    int temp;
    temp=*c;
    *c=*b;
    *b=temp;
}
int randPartition(int *a,int p,int r)
{
    int dim= r-p;
    srand(2);
    int s= rand() %dim + p ;
    scambia(&a[s],&a[r]);
    int x=a[r-1];
    int i = p-1;
    for(int j=p;j<r-1;j++)
    {
        if (a[j]<=x)
        {
            i++;
            scambia(&a[i],&a[j]);
        } 
    }
    i++;
    scambia(&a[i],&a[r-1]);        
return i;
}

void QuickSort(int *a,int p,int r)
{
    if(p<r)
    {
        int q=randPartition(a,p,r);
        QuickSort(a,p,q);       //  q e non q-1 come da pseudo-codice, perchè q mi serve come dim array
                                //  non come indice ultimo elemento se no salto di due in due.
        QuickSort(a,q+1,r);
    }
}

int main(){
    int a[10]=/*0{6,6,4,3,5,7,9,2,8,0};*/{0,2,9,8,25,8,74,21,11,100};
    int p=0;
    int r=10;
   QuickSort(a,p,r);
   //scambia(a[0],a[1]);
    for(int i=0;i<r;i++)
        printf("%d ",a[i] );


return 0;
}