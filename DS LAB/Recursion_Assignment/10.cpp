#include<stdio.h>

int linear_search(int a[],int n,int k)
{

    if(n==0) return -1;
    if(a[n-1] == k) return n-1;
    else return linear_search(a,n-1,k);



}






main()
{
    int a[1000],n,i,k;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&k);
    printf("%d\n",linear_search(a,n,k));


}




