#include<bits/stdc++.h>
using namespace std;

int e=0;



int precedence(char a)
{
    if(a=='/' || a=='*') return 2;
    if(a=='+' || a=='-') return 1;


}

bool bracket(char a)
{
    if(a=='(' || a=='{' || a=='[') return true;
    else return false;
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
       char o=l.delete_back();
       return o;
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
    l.isEmpty();
   }

   void print_stack()
   {
       l.printlist();
   }
};


main()
{
    char s[100010],a[100010];
    int j,p=0,n;
    gets(s);
    stack1 stk;
    n=strlen(s);
    for(j=0;j<=n;j++)
    {
        //stk.print_stack();
        if(j==n)
        {
            //a[p]=s[i];
            //p++;
            while(!(stk.isEmpty()))
            {
               // printf("pop %c\n",stk.pop());

                a[p]=stk.pop();
                p++;
                //stk.print_stack();
            }
        }
        else

            {

            if((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z'))
            {
                a[p]=s[j];
                p++;
            }

            if(s[j]=='(' || s[j]=='{' || s[j]=='[')
                {
                    stk.push(s[j]);
                }

            if(s[j]=='+' || s[j]=='-' || s[j]=='*' || s[j]=='/')
            {
                if(stk.isEmpty()) stk.push(s[j]);
                else if((stk.top())=='(' || (stk.top())=='[' || (stk.top())=='{') stk.push(s[j]);
                else if(precedence(stk.top())>= precedence(s[j]))
                {
                    a[p]=stk.pop();
                    p++;
                    stk.push(s[j]);
                }
                else stk.push(s[j]);
            }

            if(s[j]==')' || s[j]=='}' || s[j]==']')
            {
                while(!bracket(stk.top()))
                {
                    a[p]=stk.pop();
                    p++;
                }
                stk.pop();
            }




            }
    }

    for(j=0;j<p;j++)
    {
        printf("%c",a[j]);
    }
    printf("\n");

    return 0;


}
