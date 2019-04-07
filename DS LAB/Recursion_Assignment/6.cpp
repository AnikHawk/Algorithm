#include<stdio.h>

int numbers_odd(int a[],int n)
{

    if(n==0) return 0;

    if(a[n-1]%2==1) return 1+numbers_odd(a,n-1);
    else return numbers_odd(a,n-1);



}





main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d\n",numbers_odd(a,n));

}



