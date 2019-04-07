#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(a%b==0) return b;
    int c = a%b;
    a=b;
    b=c;
    return gcd(a,b);
}

main()
{
    int n,r;
    cin>>n>>r;
    printf("%d\n",gcd(n,r));
}
