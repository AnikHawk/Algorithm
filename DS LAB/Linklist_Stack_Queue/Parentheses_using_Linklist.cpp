
#include<bits/stdc++.h>
using namespace std;

struct linklist
{
    struct node
    {
        int val;
        node *next;

    };

    node *head=NULL,*tail=NULL,*p;

    void insert_back(int x)
    {
        node *a = (node *) malloc(sizeof(node));
        a->val=x;
        a->next=NULL;


        if(head==NULL)
        {
            head=a;
            tail=a;

        }
        else
        {
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=a;
            tail=a;

        }

    }

    void insert_front(int x)
    {
        node *a=(node *) malloc(sizeof (node));

        a->next=NULL;
        a->val=x;
        if(head==NULL)
        {
            head=a;
            tail=a;

        }
        else
        {

            a->next= head;
            head=a;
        }
    }

    int delete_back()
    {
        if(head==NULL)
        {
            printf("Delete function cannot be performed\n");
            return -1;
        }
        else if(head->next==NULL)
        {
            head=NULL;
            tail=NULL;
        }

        else
        {
            p=head;
            while(p->next->next!=NULL)
            {
                p=p->next;
            }
            int n=p->next->val;
            p->next=NULL;
            tail=p;


            return n;

        }
    }

    int delete_front()
    {
        if(head==NULL)
        {
            printf("Delete function cannot be performed\n");
            return -1;
        }
        else if(head->next==NULL)
        {
            int n=head->val;
            head=NULL;
            tail=NULL;

            return n;
        }
        else
        {
            int n=head->val;
            head=head->next;
            return n;
        }
    }

    bool isEmpty()
    {
        if(head==NULL) return true;
        else return false;
    }

    void printlist()
    {
        if(head==NULL) printf("Empty\n");
        else
        {
            p=head;
            while(p!=NULL)
            {
                printf("%d ",p->val);
                p=p->next;
            }
            printf("\n");
        }
    }



};



struct stack1
{

   linklist l;

   void push(int x)
   {
       l.insert_back(x);

   }

   int pop()
   {
       return l.delete_back();
   }

   int top1()
   {
       if(l.tail!=NULL)return l.tail->val;
       else
       {
           printf("top Empty\n");
           return -1;
       }

   }
   bool isEmpty()
   {
       if(l.head==NULL) return true;
       else return false;
   }

   void print_stack()
   {
       l.printlist();
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
