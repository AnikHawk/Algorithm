#include<bits/stdc++.h>
using namespace std;

int e=0;



int precedence(char a)
{
    if(a=='/' || a=='*') return 2;
    if(a=='+' || a=='-') return 1;

}

struct linklist
{
    struct node
    {
        char val;
        node *next;

    };

    node *head=NULL,*tail=NULL,*p;

    void insert_back(char x)
    {
        e++;
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

    void insert_front(char x)
    {
        e++;
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

    char delete_back()
    {
        e--;
        if(head==NULL)
        {
            printf("Delete function cannot be performed\n");
            return -1;
        }
        else if(head->next==NULL)
        {
            char t=head->val;
            head=NULL;
            tail=NULL;
            return t;
        }

        else
        {
            p=head;
            while(p->next->next!=NULL)
            {
                p=p->next;
            }
            char n=p->next->val;
            p->next=NULL;
            tail=p;


            return n;

        }
    }

    char delete_front()
    {
        e--;
        if(head==NULL)
        {
            printf("Delete function cannot be performed\n");
            return -1;
        }
        else if(head->next==NULL)
        {
            char n=head->val;
            head=NULL;
            tail=NULL;

            return n;
        }
        else
        {
            char n=head->val;
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
                printf("%c",p->val);
                p=p->next;
            }
            printf("\n");
        }
    }



};



struct stack1
{

   linklist l;

   void push(char x)
   {
       l.insert_back(x);

   }

   char pop()
   {
       return l.delete_back();
   }

   char top()
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

         int n,j,t;
         char x;
        linklist l;
        scanf("%d",&t);



        while (t--)
        {
            scanf("%d",&n);

            if(n==1)
        {
            scanf(" %c",&x);
            l.insert_back(x);



        }

        if(n==2)
        {
            scanf(" %c",&x);
            l.insert_front(x);

        }

        if(n==3)
        {
            l.delete_back();
        }

        if(n==4)
        {
            l.delete_front();
        }



        if(n==7)
        {
            l.printlist();
            printf("%d",e);
        }



        }

}
