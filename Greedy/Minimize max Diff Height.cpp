#include<bits/stdc++.h>
using namespace std;

int minimize(int n, int ara[], int k){

    sort(ara, ara+n);
    int init = ara[n-1] - ara[0];
    int small = ara[0] + k;
    int big = ara[n-1] - k;
    if(small>big) swap(small,big);

    for(int i = 1;i<n-1;i++){
        int sub = ara[i] - k;
        int add = ara[i] + k;

        if(sub<small && add>big){
            if(big-sub<=add-small) small = sub;
            else big = add;
        }
        cout<<"Big: "<<big<<" Small: "<<small<<endl;
    }

    return min(init, big-small);


}

int main()
{
    int n = 4;
    int ara[] = {1, 10, 12, 15};
    int k = 3;
    cout<<minimize(n, ara, k);
    return 0;
}
