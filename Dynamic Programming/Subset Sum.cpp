
#include <stdio.h>

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{

    bool subset[n+1][sum+1], in, ex;

    for (int i = 0; i <= n; i++)
      subset[i][0] = true;


    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;


     for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
         if (j >= set[i-1]){
            in = subset[i - 1][j-set[i-1]];
            ex = subset[i-1][j];
         }
         else{
            in = false;
            ex = subset[i-1][j];
         }
           subset[i][j] = in || ex;

       }
     }

     return subset[n][sum];
}

int main()
{
  int set[] = {1,2,3};
  int sum = 7;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}
