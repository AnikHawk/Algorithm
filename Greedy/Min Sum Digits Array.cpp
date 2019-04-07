#include<bits/stdc++.h>
using namespace std;

int minSum(int n, int ara[]){
    sort(ara,ara+n);
    string num1,num2;
    for(int i =0;i<n;i++){
        num1+= (48+ara[i++]);
        if(i<n) num2+= (48+ara[i]);
    }
    //cout<<num1<<" "<<num2<<endl;
    int a = atoi(num1.c_str());
    int b = atoi(num2.c_str());

    return a+b;
}


int main(){
    int n = 6;
    int ara[] =  {6, 8, 4, 5, 2, 3};
    cout<<minSum(n, ara);

    return 0;
}
