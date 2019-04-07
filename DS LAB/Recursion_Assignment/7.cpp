#include<stdio.h>

int max_of_array(int a[],int n)
{

    if(n==0) return a[0];
    int x= max_of_array(a,n-1);
    if(a[n-1]>x) return a[n-1];
    else return x;



}





main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d\n",max_of_array(a,n));

}




