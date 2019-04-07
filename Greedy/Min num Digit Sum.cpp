#include<bits/stdc++.h>
using namespace std;

void minNum(int s, int d){
    if(s==0 || d == 0) return;
    if(s>9*d) return;
    int digits = d;
    int num[digits];
    s--;
    while(--digits){
        if(s>9){
            num[digits] = 9;
            s-=9;
        }
        else{
            num[digits] = s;
            s = 0;
        }
    }

    num[0] = s + 1;
    for(int i =0;i<d;i++) cout<<num[i];
    cout<<endl;
    return;
}


int main(){
    int s, d;
    while(1){
    cin>>s>>d;
    minNum(s,d);
    }
    return 0;
}
