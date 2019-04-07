#include<stdio.h>


struct stack
{
    int top=-1,a[100],i;


    void push(int x)
    {
        top++;
        a[top]=x;

    }

    int pop()
    {
        top--;
        return a[top+1];
    }

    int top1()
    {
        return a[top];
    }

    void print()
    {
        for(i=0;i<=top;i++)
        {
            printf("%d ",a[i]);

        }
        printf("\n");
    }
};

main()
{
    stack s;
    s.push(2);
    s.print();
    s.push(3);
    s.print();
    s.push(4);
    s.print();
    printf("%d\n",s.top1());
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.push(10);
    s.print();

    return 0;
}
