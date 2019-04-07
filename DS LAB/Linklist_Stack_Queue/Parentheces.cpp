#include<bits/stdc++.h>
using namespace std;

struct stack1
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

    bool isEmpty()
    {
        if(top==-1) return true;
        else return false;
    }
};



main()
{
    stack1 stk;
    char s[10000];
    int i;
    gets(s);
    for(i=0;s[i];i++)
    {
        if(s[i]=='(' || s[i]== '{' || s[i]=='[') stk.push(s[i]);
        if(s[i]==')')
        {
            if(stk.top1()=='(') stk.pop();
            else
            {
                //flag=1;
                break;
            }
        }
        if(s[i]=='}')
        {
            if(stk.top1()=='{') stk.pop();
            else
            {
                //flag=1;
                break;
            }
        }
        if(s[i]==']')
        {
            if(stk.top1()=='[') stk.pop();
            else
            {
               // flag=1;
                break;
            }
        }

    }

    if(stk.isEmpty()== false) printf("Not Balanced\n");
    else printf("Balanced\n");

    return 0;
}
