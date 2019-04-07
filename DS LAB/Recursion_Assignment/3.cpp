#include<stdio.h>

void print_array_regular(int a[],int n)
{
    if(n==0) return;
    print_array_regular(a,n-1);
    printf("%d ",a[n-1]);
}





main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    print_array_regular(a,n);

}
