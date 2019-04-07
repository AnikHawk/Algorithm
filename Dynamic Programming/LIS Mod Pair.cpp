#include<bits/stdc++.h>
using namespace std;


int maxChain( pair<int,int> arr[], int n)
{
    int i, j, res = INT_MIN;
    int maxLen[n];


    for ( i = 0; i < n; i++ )  maxLen[i] = 1;

    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i].first > arr[j].second && maxLen[i] < maxLen[j] + 1)
                maxLen[i] = maxLen[j] + 1;


    for ( i = 0; i < n; i++ ) res = max(res,maxLen[i]);

    return res;
}

int main()
{
    struct pair<int,int> arr[] = { {5, 24}, {15, 25},{27, 40}, {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxChain( arr, n )<<endl;
    return 0;
}
