#include<bits/stdc++.h>
using namespace std;

int nCr(int n,int r)
{

    if(n==r) return 1;
    if(r==1) return n;
    if(r>n) return 0;

    return (nCr(n-1,r-1)+nCr(n-1,r));
}

main()
{
    int n,r;
    cin>>n>>r;
    printf("%d\n",nCr(n,r));
}
