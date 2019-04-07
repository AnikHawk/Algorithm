#include<bits/stdc++.h>
using namespace std;

int findMin(int arr[], int low, int high)
{
    if (high < low)  return arr[0];
    if (high == low) return arr[low];
    int mid = low + (high - low)/2;

    if ( arr[mid+1] < arr[mid]) return arr[mid+1];
    if ( arr[mid] < arr[mid-1]) return arr[mid];

    if (arr[high] > arr[mid]) return findMin(arr, low, mid-1);
    return findMin(arr, mid+1, high);
}

int main()
{
   int t,n;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        int arr[1000];
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<findMin(arr,0, n-1)<<endl;
    }
    return 0;
}
