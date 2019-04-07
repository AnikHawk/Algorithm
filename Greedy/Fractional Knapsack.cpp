#include<bits/stdc++.h>
using namespace std;


struct item{
    int value, weight;
    item(int v, int w){
    value = v;
    weight = w;
    }
    bool operator <(const item& x) const{
        double a = value/weight;
        double b = x.value/x.weight;
        return a>b;
    }
};

int knapsack(int n, int itemList[][2], int w){
   vector<item> lst;
   for(int i =0;i<n;i++){
   lst.push_back( item(itemList[i][0], itemList[i][1]));
   }
   sort(lst.begin(),lst.end());
   int rem = w;
   int result = 0;

   for(int i =0;i<n;i++){
    int amount = min(rem, lst[i].weight);
    result+=(double)amount*lst[i].value/lst[i].weight;
    rem-=amount;
   }
   return result;
}

int main(){
    int n = 3;
    int w = 50;
    int itemList[][2] =  { {100, 20}, {120, 30},{60,10}}; //value, weight
    cout<<knapsack(n, itemList, w);
    return 0;
}
