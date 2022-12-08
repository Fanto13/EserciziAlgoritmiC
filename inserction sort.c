#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void scambia(int *a,int *b);

int main()

{	
	int n=100;
	int a[n];
	int i,j;
    for(i=0;i<n;i++)
    {
    	a[i]=(rand() % n+1);

    	printf("%d \n",&a[i]);

    }
	for(i=0;i<n;i++)
	{
      
      for(j=1;j<n;j++)
      {

      	if(a[i]>a[j])
      	{

      		scambia(&a[i],&a[j]);

      	}

      }

	}

	for(i=0;i<n;i++)
    {
    

    	printf("%d \n",a[i]);

    }
return 0;
} 

void scambia(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
