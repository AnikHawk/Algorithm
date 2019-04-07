#include<bits/stdc++.h>
using namespace std;

int findMin(int n, int k, int price[]){
    int result = 0;
    sort(price, price+n);
    for(int i =0;i<n;i++){
        result+=price[i];
        n-=k;
    }
    return result;
}

int findMax(int n, int k, int price[]){
    int result = 0;
    sort(price, price+n, greater<int>());
     for(int i =0;i<n;i++){
        result+=price[i];
        n-=k;
    }
    return result;
}

int main(){
    int n,k;
    int price[100];
    cin>>n;
    for(int i =0;i<n;i++) cin>>price[i];
    cin>>k;
    cout<<findMin(n,k,price)<<" ";
    cout<<findMax(n,k,price)<<endl;
    return 0;
}
