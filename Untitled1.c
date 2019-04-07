#include<stdio.h>
int ara[100];
int ara2[100];
int merging (int low, int mid, int high)
{
    int l1, l2, i;
    for (l1=low, l2=mid+1, i=low; l1<=mid && l2<=high; i++)
    {
        if (ara[l1]<ara[l2])
        {
            ara2[i]=ara[l1++];
        }
        else
        {
            ara2[i]=ara[l2++];
        }
    }

    while (l1<=mid)
    {
        ara2[i++]=ara[l1++];
    }
    while (l2<high)
    {
        ara2[i++]=ara[l2++];
    }
    printf("sorted: \n");
    for (i=low; i<=high; i++)
    {
        printf("%d ",ara2[i]);
        ara[i]=ara2[i];
    }
    printf("\n");

}
void sort (int low, int high)
{
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        sort (low, mid);
        sort (mid+1, high);
        merging (low, mid, high);
    }
    else
        return;

}

int main()
{
    int t,i,j;
    scanf("%d", &t);
    for (i=0; i<t; i++)
        scanf("%d",&ara[i]);
    sort (0, t-1);
    for (i=0; i<t; i++)
    {
        printf("%d ", ara[i]);
    }
    return 0;
}
