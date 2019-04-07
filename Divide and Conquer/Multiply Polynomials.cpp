#include<bits/stdc++.h>
using namespace std;


int* multiply(int A[], int B[], int m, int n)
{
    int *prod = new int[m+n-1];

    for (int i = 0; i<m+n-1; i++)
        prod[i] = 0;

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            prod[i+j] += A[i]*B[j];
    }
    return prod;
}


void printPoly(int poly[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << poly[i];
        if (i != 0)
            cout << "x^" << i ;
        if (i != n-1)
            cout << " + ";
    }
    cout<<endl;
}


int main()
{

    int A[] = {5, 0, 10, 6}; //5 + 10x^2 + 6x^3


    int B[] = {1, 2, 4};  //  1 + 2x + 4x^2
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);

    cout << "First polynomial is: ";
    printPoly(A, m);
    cout << "Second polynomial is: ";
    printPoly(B, n);

    int* prod = multiply(A, B, m, n);

    cout << "Product polynomial is: ";
    printPoly(prod, m+n-1);

    return 0;
}
