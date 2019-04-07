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
            else if(X[i-1] == Y[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            //else arr[i][j] = 0 //for LC substring
        }
    }

    string res = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (arr[i][j] == arr[i-1][j-1] + 1)
        {
            res = res + X[i-1]; //not X[i-1]
            i--;
            j--;
        }
        else if (arr[i][j] == arr[i-1][j]) i--;
        else j--;
    }
    reverse(res.begin(), res.end());
    cout<<res<<endl;

    return arr[m][n];
}


int main()
{
    string X = "abcdefghijklmnopqrstuvwxyz";
    string Y = "a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0";

    int m = X.length();
    int n = Y.length();

    printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

    return 0;
}

/*
//PRINT LCS

 int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }

   // Print the lcs
   cout << "LCS of " << X << " and " << Y << " is " << lcs;
   */
