#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[],int n)
{
    for(int k=0; k<n-1; k++)
    {
        for(int i=0; i<n-k-1; i++)
        {
            if(arr[i]>arr[i+1])swap(arr[i],arr[i+1]);
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
    bubble_sort(arr,10);
    print(arr,10);
    return 0;
}
