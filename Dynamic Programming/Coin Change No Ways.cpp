#include<stdio.h>

int count( int S[], int size, int val )
{
    int i, j, in, ex;
    int table[size][val+1];

    for (i=0; i<size; i++)
        table[i][0] = 0;


    for (i = 0; i < size; i++)
    {
        for (j = 1; j <= val; j++)
        {
            if(j>S[i]) in = table[i][j-S[i]];
            else if(j==S[i]) in = 1;
            else in = 0;

            if(i>0) ex = table[i-1][j];
            else ex = 0;

            table[i][j] = in + ex;
        }
    }
    return table[size-1][val];
}

int main()
{
    int arr[] = {5,6, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 6;
    printf(" %d ", count(arr, m, n));
    return 0;
}


/*

int count( int S[], int m, int n )
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is consturcted
    // in bottom up manner using the base case (n = 0)
    int table[n+1];

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];

    return table[n];
}

*/
