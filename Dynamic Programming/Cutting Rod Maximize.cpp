#include<bits/stdc++.h>
using namespace std;

int cutRod(int arr[], int n)
{
    int dp[n+1][n+1];

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            if(i==0 || j == 0)
            {
                 dp[i][j] = 0;
            }
            else if(i<=j)
            {
                dp[i][j] = max(dp[i-1][j], (dp[i][j-i] +arr[i-1]));
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int i =0;i<=n;i++)
    {
        for(int j = 0;j<=n;j++) printf("%5d",dp[i][j]);
        cout<<endl;
    }
        return dp[n][n];
}



int main()
{
    int arr[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf(" %d ", cutRod(arr, n));
    return 0;
}
