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


struct Queue
{
    linklist l;
    void enqueue(int x)
    {
        l.insert_back(x);
    }

    int dequeue()
    {
        int x= l.delete_front();
        return x;
    }

    void print_queue()
    {
        l.printlist();
    }
    bool isEmpty()
    {
        if(l.isEmpty()== true) printf("Empty\n");
        else printf("Not Empty\n");
    }

};


main()
{
    Queue q;
    int n,x,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            scanf("%d",&x);
            q.enqueue(x);
        }

        if(n==2)
        {
            q.dequeue();
        }
        if(n==3)
        {
            q.print_queue();
        }
        if(n==4)
        {
            q.isEmpty();
        }
    }


}
