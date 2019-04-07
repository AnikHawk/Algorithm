#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j = i;
        while(j>0 && (arr[j]<arr[j-1]))
        {
            swap(arr[j--],arr[j-1]);
        }
    }
}
void print(int arr[],int sz)
{
    for(int i=0; i<sz; i++)cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[10];
    srand (time(NULL));
    for(int i=0; i<10; i++)
    {
        arr[i]=-2500+rand()%5000;
    }
    print(arr,10);
    insertion_sort(arr,10);
    print(arr,10);
    return 0;
}
