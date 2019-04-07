#include<bits/stdc++.h>
using namespace std;

void generateMin(int n, int ara[], int k){

    for(int i =0;i<n;i++){
        int minPos = i;
        for(int j = i+1;j-i<=k;j++){
            if(ara[minPos]> ara[j]) minPos = j;
        }

        for(int j = minPos;j>i;j--){
            swap(ara[j],ara[j-1]);
        }
        k -= minPos - i;
    }

    for(int i =0;i<n;i++) cout<<ara[i]<<" ";
}

int main(){
    int n = 5;
    int ara[] = {7, 6, 9, 2, 1};
    int k =1;
    generateMin(n,ara,k);
    return 0;
}
