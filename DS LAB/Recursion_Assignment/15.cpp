#include<bits/stdc++.h>
using namespace std;


int fibonacci(int n)
{
    if(n==0 || n==1) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}


main()
{
    int n;
    cin>>n;
    printf("%d\n",fibonacci(n));
}
