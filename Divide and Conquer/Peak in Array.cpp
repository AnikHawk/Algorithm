#include<bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int lo, int hi)
{
    if(hi==lo) return arr[lo];
    if(hi==lo+1) return max(arr[hi],arr[lo]);
    int mid = (lo+hi)/2;
    if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]) return arr[mid];

    if(arr[mid]<arr[mid+1]) return findPeak(arr, mid+1,hi);
    return findPeak(arr,lo,mid-1);


}

/*
int findPeakUtil(int arr[], int low, int high, int n)
{
    // Find index of middle element
    int mid = low + (high - low)/2;  // (low + high)/2

    // Compare middle element with its neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
            (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;

    // If middle element is not peak and its left neighbour is greater
    // than it, then left half must have a peak element
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return findPeakUtil(arr, low, (mid -1), n);

    // If middle element is not peak and its right neighbour is greater
    // than it, then right half must have a peak element
    else return findPeakUtil(arr, (mid + 1), high, n);
}

*/

int main()
{
    int t,n;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        int arr[1000];
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<findPeak(arr,0, n-1);
    }
    return 0;
}
