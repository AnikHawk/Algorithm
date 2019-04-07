
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


int searchMaxIndex(int start, int end, int arr[], int x, int n)
{
    if(start<=end){
    int mid = (start+end)/2;
    if(arr[mid] == x && mid==n-1) return mid;
    if(arr[mid] == x && arr[mid+1]>x) return mid;
    if(x<arr[mid])return  searchMaxIndex(start, mid-1, arr,x,n);
    return searchMaxIndex(mid+1, end, arr,x,n);
    }
    return -1;
}

int countFreq(int n, int arr[], int x)
{
    int start = searchMinIndex(0,n-1,arr,x);
    if(start == -1) return 0;
    int end = searchMaxIndex(start,n-1,arr,x,n);
    return end-start+1;

}

int main()
{

    int arr[] = {1, 1, 2, 2, 2, 2, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    cout<<countFreq(n,arr, x)<<endl;
    return 0;
}
