#include<stdio.h>

void numbers_div3(int a[],int n)
{
    if(n==0) return;
    numbers_div3(a,n-1);
    if(a[n-1]%3==0) printf("%d ",a[n-1]);


}





main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    numbers_div3(a,n);

}


