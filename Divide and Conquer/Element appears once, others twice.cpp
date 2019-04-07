#include<bits/stdc++.h>
using namespace std;

int searchSingle(int arr[],int lo, int hi){
    if(lo==hi) return arr[lo];
    int mid = (lo+hi)/2;
    if(mid%2){
         if(arr[mid]==arr[mid-1]) return searchSingle(arr,mid+1,hi);
         else return searchSingle(arr,lo,mid-1);
    }
    else{
        if(arr[mid]==arr[mid+1]) return searchSingle(arr,mid+2,hi);
        else return searchSingle(arr,lo,mid);
    }
    return -1;

}


int main()
{
    int arr[] = {1, 1, 2, 2, 5, 5, 6, 7, 7};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<searchSingle(arr, 0, len-1)<<endl;
    return 0;
}
