#include <bits/stdc++.h>
using namespace std;

int searchMinIndex(int start, int end, int arr[], int x)
{
    int mid = (start+end)/2;
    if(start == end )
    {
        if(arr[start] == x) return start;
        else return end+1;
    }
    if(arr[mid] == x)
    {
        return searchMinIndex(start, mid-1, arr, x);
    }
    else return searchMinIndex(mid+1, end, arr, x);
}

bool isMajority(int n, int arr[], int x)
{
    int start = searchMinIndex(0,n,arr,x);
    if(arr[start+ n/2] == x) return 1;
    return 0;

}

int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int x = 2;
    cout<<isMajority(n,arr, x)<<endl;
    return 0;
}
