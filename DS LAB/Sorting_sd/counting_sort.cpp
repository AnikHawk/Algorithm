#include<bits/stdc++.h>
using namespace std;
void counting_sort(int arr[],int n)
{
    int mx=50000;
    int k=0;
    int mp[2*mx+10];
    memset(mp,0,sizeof(mp));
    for(int i=0;i<n;i++)mp[mx+arr[i]]++;
    for(int i=0;i<=2*mx;i++)
    {
        while(mp[i])
        {
            arr[k++]=i-mx;
            mp[i]--;
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
    counting_sort(arr,10);
    print(arr,10);
    return 0;
}

