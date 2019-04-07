
#include <bits/stdc++.h>
using namespace std;

double MO2(int a, int b)
{
    return ( a + b ) / 2.0;
}


double MO3(int a, int b, int c)
{
    return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

double MO4(int a, int b, int c, int d)
{
    int Max = max( a, max( b, max( c, d ) ) );
    int Min = min( a, min( b, min( c, d ) ) );
    return ( a + b + c + d - Max - Min ) / 2.0;
}


double medianSingle(int arr[], int n)
{
    if (n == 0) return -1;
    if (n%2 == 0) return (arr[n/2] + arr[n/2-1])/2;
    else return arr[n/2];
}


float findMedianUtil( int A[], int N, int B[], int M )
{
    if (N == 0) return medianSingle(B, M);
    if (N == 1)
    {
        if (M == 1) return MO2(A[0], B[0]);

        if (M%2)
            return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) );
        else
            return MO3( B[M/2], B[M/2 - 1], A[0] );
    }

    else if (N == 2)
    {
        if (M == 2) return MO4(A[0], A[1], B[0], B[1]);
        if (M%2) return MO3 ( B[M/2],max(A[0], B[M/2 - 1]),min(A[1], B[M/2 + 1]));
        else return MO4 ( B[M/2],B[M/2 - 1],max( A[0], B[M/2 - 2] ),min( A[1], B[M/2 + 1] ));
    }

    int idxA = ( N - 1 ) / 2;
    int idxB = ( M - 1 ) / 2;


    if (A[idxA] <= B[idxB] )return findMedianUtil(A + idxA, N/2 + 1, B, M - idxB ); //M - idxA
    else return findMedianUtil(A, N/2 + 1, B + idxB, M - idxB ); //B + idxA, M - idxA
}


float findMedian( int A[], int N, int B[], int M )
{
    if (N > M)
        return findMedianUtil( B, M, A, N );

    return findMedianUtil( A, N, B, M );
}

int main()
{
    int A[] = {9,12,13};
    int B[] = {5,7,8,10};

    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);

    printf("%.2f\n", findMedian( A, N, B, M ) );
    return 0;
}
