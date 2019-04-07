#include<bits/stdc++.h>
using namespace std;


int Binary_search(int a[],int high,int low,int key)
{
    if(high<low) return -1;

    int mid=(high+low)/2;
    if(a[mid]==key) return mid;
    else if(a[mid]>key)
    {
        return Binary_search(a,mid-1,low,key);
    }
    else if(a[mid]<key)
    {
        return Binary_search(a,high,mid+1,key);
    }
}


main()
{
     int a[1000],n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    cin>>x;
    printf("%d\n",Binary_search(a,n-1,0,x));
   // for(i=0;i<n;i++) cout<<a[i]<<" ";
}
