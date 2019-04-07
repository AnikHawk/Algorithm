#include<bits/stdc++.h>
using namespace std;


/*
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
*/

int maxStock(int n, int k, int price[]){
    int mx = 0;
    vector < pair <int, int > > stocks;
    for(int i=0;i<n;i++){
        stocks.push_back(make_pair(price[i],i+1));
    }
    sort(stocks.begin(),stocks.end());

    for(int i=0;i<n;i++){
        int amount = min(stocks[i].second, k/stocks[i].first);
        mx+=amount;
        k -= stocks[i].first*amount;
    }

    return mx;
}



int main(){
    int n,k;
    int price[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>price[i];
    cin>>k;

    cout<<maxStock(n,k,price)<<endl;




}
