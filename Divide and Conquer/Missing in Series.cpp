#include<bits/stdc++.h>
using namespace std;


int findMissing(int arr[], int lo, int hi, int diff){
    if(hi>lo){
    int mid = (lo+hi)/2;
    if(arr[mid+1]-arr[mid]!=diff) return arr[mid]+diff;
    if(arr[mid]-arr[mid-1]!=diff) return arr[mid]-diff;

    if(arr[mid]==arr[0]+diff*mid) return findMissing(arr,mid+1,hi,diff);
    return findMissing(arr,lo,mid-1,diff);
    }
    return -1;
}

int main(){
    int arr[] = {2, 4, 6, 10, 12, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = (arr[n-1]-arr[0])/n;
    cout<<findMissing(arr, 0,n-1,diff)<<endl;
    return 0;
}
