#include<bits/stdc++.h>
using namespace std;

void insertion_sort_ascending(int arr[],int n)
{
    int i=0,j=0;

    for(i=0;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(arr[i]<=arr[j])
            {
                swap(arr[i],arr[j]);
                i--;
            }
        }
    }
}

void insertion_sort_descending(int arr[],int n)
{
    int i=0,j=0;

    for(i=0;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(arr[i]>=arr[j])
            {
                swap(arr[i],arr[j]);
                i--;
            }
        }
    }
}

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


main()
{
    int n,arr[100],i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    insertion_sort_ascending(arr,n);
    print_array(arr,n);
    insertion_sort_descending(arr,n);
    print_array(arr,n);
}
