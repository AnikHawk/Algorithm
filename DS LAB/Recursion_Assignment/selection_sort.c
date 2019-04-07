#include<bits/stdc++.h>
using namespace std;

void selection(int a[],int m)
{
    if(n==0) return 0;
    int x= (a,n-1);
    if(a[n-1]>a[x]) return n-1;
    else return x;

}


void selection_sort(int a[],int n)
{
    if(n==1) return;
    int i=selection(a,n-2);
    if(a[i]>a[n-1]) swap(a[i],a[n-1]);
    selection sort(a,n-1);
}


main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    bubble_sort(a,n);
    for(i=0;i<n;i++) cout<<a[i]<<" ";
}

