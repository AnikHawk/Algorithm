#include<bits/stdc++.h>
using namespace std;


int maxTime(int n, int mice[],int holes[]){
    int res = 0;
    sort(mice, mice+n);
    sort(holes, holes+n);
    for(int i=0;i<n;i++) res = max(abs(mice[i]-holes[i]),res);
    return res;
}

int main(){
    int n;
    int mice[100];
    int holes[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>mice[i];
    for(int i=0;i<n;i++) cin>>holes[i];

    cout<<maxTime(n, mice, holes);

    return 0;
}
