#include<bits/stdc++.h>
using namespace std;


int minCost(int m, int n, int x[], int y[])
{
    sort(x, x+m-1, greater<int>());
    sort(y, y+n-1, greater<int>());
    int res = 0, i = 0, j = 0;
    int horPc = 1;
    int vrtPc = 1;
    while(horPc<m && vrtPc<n)
    {
        if(x[i]>y[j])
        {
            res+= vrtPc*x[i++];
            horPc++;
        }
        else
        {
            res+= horPc*y[j++];
            vrtPc++;
        }
    }
    while(horPc<m){
        res+= vrtPc*x[i++];
        horPc++;
    }
    while(vrtPc<n){
        res+= horPc*y[j++];
        vrtPc++;
    }

    return res;


}


int main()
{
    int m = 6, n = 4;
    int x[] = {2, 1, 3, 1, 4};
    int y[] = {4, 1, 2};
    cout<<minCost(m,n,x,y);
    return 0;
}
