#include <bits/stdc++.h>
using namespace std;

int searchMinIndex(int start, int end, int arr[], int x)
{
    if(start<=end){
    int mid = (start+end)/2;
    if(arr[mid] == x && mid==0) return mid;
    if(arr[mid] == x && arr[mid-1]<x) return mid;
    if(x>arr[mid])return searchMinIndex(mid+1, end, arr,x);
    return searchMinIndex(start, mid-1, arr,x);
    }
    return -1;
}

bool isMajority(int n, int arr[], int x)
{
    int start = searchMinIndex(0,n-1,arr,x);
    cout<<"start "<<start<<endl;
    if(start == -1 || start+n/2>n-1) return 0;
    if(arr[start+ n/2] == x) return 1;
    return 0;

}

int main()
{

    int arr[] = {1, 1, 1, 2, 2, 2, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    cout<<isMajority(n,arr, x)<<endl;
    return 0;
}
