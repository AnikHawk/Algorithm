#include<bits/stdc++.h>
using namespace std;

void selection_sort_ascending(int arr[],int n)
{
    int i,j,index;

    for(i=0;i<n;i++)
    {
        int mini=arr[i];
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<mini)
            {
                mini=arr[j];
                index=j;
            }
        }
        if (i!=index) swap(arr[i],arr[index]);
    }
}

void selection_sort_descending(int arr[],int n)
{
    int i,j,index;

    for(i=0;i<n;i++)
    {
        int mx=arr[i];
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]>mx)
            {
                mx=arr[j];
                index=j;
            }
        }
        if (i!=index) swap(arr[i],arr[index]);
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

    selection_sort_ascending(arr,n);
    print_array(arr,n);
    selection_sort_descending(arr,n);
    print_array(arr,n);
}
