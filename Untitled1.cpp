#include<stdio.h>
int main()
{
    int n,temp,i, ct=0, max=0, min=9999999999999999;
    scanf("%d", &n);
    int ara[n];
    for (i=0; i<n; i++)
    {
        scanf("%d", &ara[i]);
        if (ara[i]>ara[i+1])
        {
            temp = ara[i];
            ara[i]=ara[i+1];
            ara[i+1]=temp;
        }
        if (ara[i]>max)
        {
            max=ara[i];
        }
        if (ara[i]<min)
        {
            min=ara[i];
        }
    }
    for(i=0; i<n; i++)
    {
        if(ara[i]>min && ara[i]<max)
            ct++;
    }
    printf("%d", ct);

    return 0;
}
