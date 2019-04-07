
#include<bits/stdc++.h>
using namespace std;

int f(int x) { return (x*x - 10*x - 20); }

int binarySearch(int lo, int hi){
    if(hi>=lo){
        int mid = (lo+hi)/2;
        if(f(mid)>0 && f(mid-1)<=0) return mid;
        if(f(mid)>0 && mid==lo) return mid;
        if(f(mid)<0) return binarySearch(lo,mid-1);
        return binarySearch(mid+1,hi);
    }


}

int findFirstPositive()
{
    if(f(0)>0) return 0;
    int i = 1;
    while(f(i)<=0) i*=2;
    binarySearch(i/2,i);
}


int main(){

    cout<<findFirstPositive();

    return 0;
}
