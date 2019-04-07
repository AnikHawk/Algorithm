#include<bits/stdc++.h>
using namespace std;


int findFixed(int arr[], int low, int high)
{
    if(high >= low)
    {
        int mid = (low + high)/2;  /*low + (high - low)/2;*/
        if(mid == arr[mid]) return mid;
        if(mid > arr[mid]) return findFixed(arr, (mid + 1), high);
        else return findFixed(arr, low, (mid -1));
    }
    return -1;
}

int main()
{
    int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<< findFixed(arr, 0, n-1)<<endl;
    return 0;
}
