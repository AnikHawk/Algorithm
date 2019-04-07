#include<bits/stdc++.h>
using namespace std;


void inner_loop(int a[],int Start,int End)
{
    if(Start==End-1) return;
    if(a[Start]>a[Start+1])  swap(a[Start],a[Start+1]);
    inner_loop(a,Start+1,End);
}

void bubble_sort(int a[],int n)
{
    if(n==1) return;
    inner_loop(a,0,n);
    bubble_sort(a,n-1);
}


main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    bubble_sort(a,n);
    for(i=0;i<n;i++) cout<<a[i]<<" ";
}
