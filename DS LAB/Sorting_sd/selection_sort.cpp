#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n)
{
    int mini;
    for(int i=0;i< n-1;i++)
    {
        mini= i ;
        for(int j=i+1;j< n;j++)
        {
            if(arr[j]<arr[mini])mini=j;
        }
        swap (arr[mini],arr[i]);
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
    selection_sort(arr,10);
    print(arr,10);
    return 0;
}
