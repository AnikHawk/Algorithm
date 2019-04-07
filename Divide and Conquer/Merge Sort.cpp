#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int lo, int mid, int hi)
{
    int n1 = mid - lo + 1;
    int n2 = hi - mid;
    int i1 = 0, i2 = 0, i = lo;
    int L[n1], R[n2];
    for(int j=0; j<n1; j++) L[j] = arr[lo+j];
    for(int j=0; j<n2; j++) R[j] = arr[mid+1+j];
    while(i1<n1 && i2<n2)
    {
        if(L[i1]<R[i2]) arr[i++] = L[i1++];
        else arr[i++] = R[i2++];
    }
    while(i1<n1) arr[i++] = L[i1++];
    while(i2<n2) arr[i++] = R[i2++];


}

void mergeSort(int arr[], int lo, int hi)
{
    if(hi>lo)
    {
        int mid = (lo+hi)/2;
        mergeSort(arr,lo,mid);
        mergeSort(arr,mid+1,hi);
        merge(arr, lo, mid, hi);
    }

}


void printArray(int arr[], int size)
{

    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}
