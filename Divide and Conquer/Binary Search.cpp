#include<bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int lo, int hi, int x){
    if(hi>=lo){
    int mid = (lo+hi)/2;
    if(arr[mid] == x) return mid;
    if(arr[mid] > x) return binarySearch(arr,lo, mid-1,x);
    else return binarySearch(arr, mid+1, hi,x);
    }

    return -1;

}

int main()
{
    int arr[] = {2, 3, 4, 10, 40,60};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 60;
    int result = binarySearch(arr, 0, n-1, x);
    (result == -1)? printf("Element is not present in array")
    : printf("Element is present at index %d", result);
    return 0;


}
