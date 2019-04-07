#include<bits/stdc++.h>
using namespace std;


int searchMinIndex(int start, int end, int arr[], int x)
{
    if(start<=end){
    int mid = (start+end)/2;
    if(arr[mid] == x && mid==0) return mid;
    if(arr[mid] == x && arr[mid-1]==1) return mid;
    if(arr[mid]==1)return searchMinIndex(mid+1, end, arr,x);
    return searchMinIndex(start, mid-1, arr,x);
    }
    return -1;
}


int main(){
    int arr[] =   {1, 1, 1, 1, 0, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int minIndx = searchMinIndex(0,n-1,arr,0);
    minIndx==-1?cout<<0:cout<<n-minIndx;

return 0;
}
