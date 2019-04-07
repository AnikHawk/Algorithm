#include<bits/stdc++.h>
using namespace std;


struct Max_heap
{
    int a[100010],last_index=0,p=0,c[100010],n=0;

    void Insert(int x)
    {
        last_index++;
        n++;
        a[last_index]=x;
        shift_down(last_index);

    }

    void shift_down(int i)
    {
        if(i<=1) return;

        if(a[i]>a[i/2])
        {
            swap(a[i],a[i/2]);
            shift_down(i/2);
        }
        else return;
    }


    void print()
    {
        if(last_index==0)
        {
            printf("Heap is Empty!");
        }
        for(int i=1;i<=last_index;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }


   void  delete_root()
    {
        if(last_index==0)
        {
            printf("Heap is Empty.Root can not be deleted\n");
            return ;
        }
       // int x = a[1];
        a[1]=a[last_index];
        last_index--;
        check(1);
        //return x;

    }

    void check(int i)
    {
        if(i*2>last_index) return;
        if(i*2==last_index)
        {
            if(a[i]<a[2*i])
            {
                swap(a[i],a[2*i]);

            }
            return;
        }
        if(a[i]<a[2*i] || a[i]<a[(2*i)+1])
        {
            if(a[2*i]>a[(2*i)+1])
            {
                swap(a[i],a[2*i]);
                check(2*i);
            }
            else
            {
                swap(a[i],a[(2*i)+1]);
                check((2*i)+1);
            }
        }
        else return;
    }


    void heap_sort()
    {
        int i;
        for(i=n;i>=1;i--)
        {
           // printf("%d ",delete_root());
           delete_root();
           //c[p] = delete_root();
           //p++;
        }
        printf("In descending oder: ");
        for(i=1;i<n;i++ )
        {
            printf("%d ",a[i]);

        }
        printf("\n");



        //printf("\n");
    }
};



main()
{
    Max_heap m;
    int n,x;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("Enter a new value: ");
            scanf("%d",&x);
            m.Insert(x);

        }

        if(n==2)
        {

           m.delete_root();
           //cout<<x;
        }

        if(n==3)
        {
            m.print();
        }

        if(n==4)
        {
            printf("Heap Sort: \n");
            m.heap_sort();
            printf("\n");
        }
    }
}

