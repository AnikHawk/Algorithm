#include<bits/stdc++.h>
using namespace std;

int maximize(int n, int ara[], int k){
    int res = 0;
    priority_queue < int, vector<int>, greater<int> > pq;
    for(int i =0;i<n;i++) pq.push(ara[i]);
    for(int i=0;i<k;i++){
        int x = pq.top(); pq.pop();
        x*=-1;
        pq.push(x);
    }
    for(int i =0;i<n;i++){
     res+=pq.top();
     pq.pop();
    }
    return res;
}



int main(){
    int n = 4;
    int arr[] = {9,8,8,5} ;
    int k = 3;
    cout<<maximize(n, arr, k);

    return 0;
}
