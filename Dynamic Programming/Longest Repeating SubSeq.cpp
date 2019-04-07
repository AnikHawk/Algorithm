
#include<bits/stdc++.h>
using namespace std;


int lcs( string X, string Y, int m, int n )
{
    int arr[m+1][n+1];

    for(int i = 0; i<=m; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            if(i==0 || j == 0) arr[i][j] = 0;
            else if(X[i-1] == Y[j-1] && i!=j) arr[i][j] = arr[i-1][j-1] + 1;
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    string res = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (arr[i][j] == arr[i-1][j-1] + 1)
        {
           res = res + X[i-1];
           i--;
           j--;
        }


        else if (arr[i][j] == arr[i-1][j])
            i--;
        else
            j--;
    }


    reverse(res.begin(), res.end());
    cout<<res<<endl;
       return arr[m][n];


}



int main()
{
    string X = "AABEBCDD";
    string Y = "AABEBCDD";

    int m = X.length();
    int n = Y.length();

    printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

    return 0;
}
