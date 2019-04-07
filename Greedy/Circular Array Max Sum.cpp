#include<bits/stdc++.h>
using namespace std;


int maxSum(int n, int ara[]){
    int res =0;
    for(int i=0;i<n/2;i++){
        res -= 2*ara[i];
        res += 2*ara[n-1-i];
    }
    return res;
}


int main()
{
    int n;
    int ara[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>ara[i];
    cout<<maxSum(n,ara);

    return 0;
}



