#include<bits/stdc++.h>
using namespace std;



void merge(int arr[], int l, int r)
{
    int i, j, k;
    int m=(l+r)/2;
    int n1 =m-l+1;
    int n2 =r-m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;

    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int low, int high)
{
    if (low>=high) return;

    int m=(low+high)/2;

        mergeSort(arr, low, m);
        mergeSort(arr, m+1, high);

        merge(arr, low, high);

}


main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
    for(i=0;i<n;i++) cout<<a[i]<<" ";
}
