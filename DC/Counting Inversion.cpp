#include <stdio.h>


int count_inversion_merge(int array[], int first, int last)
{
    int mid = (first+last)/2;
    int ai = first;
    int bi = mid+1;
    int result[last-first+1], resulti=0;
    int inversion = 0, i;

    while (ai <= mid && bi <= last)
    {
        if (array[ai] <= array[bi])
        {
            result[resulti++] = array[ai++];
        }
        else
        {
            result[resulti++] = array[bi++];
            inversion += mid - ai + 1;
        }
    }

    while (ai <= mid)
         result[resulti++] = array[ai++];

    while (bi <= last)
         result[resulti++] = array[bi++];

    for (i=0 ; i<last-first+1 ; i++)
        array[i+first] = result[i];

    return inversion;
}

int count_inversion(int array[], int a, int b)
{
    int x, y, z, mid;
    if (a >= b) return 0;

    mid = (a+b)/2;

    x = count_inversion(array, a, mid);
    y = count_inversion(array, mid+1, b);
    z = count_inversion_merge(array, a, b);

    return x+y+z;
}

int main()
{
    int a[] = {1, 20, 6, 4, 5};   //{9, 8 , 7, 6, 5, 4, 3, 2, 1, 10};
    int len = 5;

    for (int i=0 ; i<len; i++) printf("%d ", a[i]);
    printf("\n");

    printf("Total inversions : %d \n", count_inversion(a, 0, len-1));

    return 0;
}
