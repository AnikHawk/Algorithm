#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n==1) return 1;
    return n*factorial(n-1);
}


main()
{
    int n;
    cin>>n;
    printf("%d\n",factorial(n));
}
