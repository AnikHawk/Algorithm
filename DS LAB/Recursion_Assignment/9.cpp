#include<stdio.h>

int sum_of_array(int a[],int n)
{

    if(n==0) return 0;
    int sum= a[n-1]+sum_of_array(a,n-1);
    return sum;



}






main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d\n",sum_of_array(a,n));


}




