#include<bits/stdc++.h>
using namespace std;


struct linklist
{
    struct node
    {
        int val;
        node *next;
        node *prev;
    };

    node *head=NULL,*tail=NULL,*p;

    void insert_last(node* p,int x)
    {
        if(head==NULL)
        {
        node *a = (node *) malloc(sizeof(node));
        a->val=x;
        a->next=NULL;
        a->prev=NULL;
        head = a;
        tail = a;
        return;

        }

        if(p->next==NULL)
        {
            node *a = (node *) malloc(sizeof(node));
        a->val=x;
        a->next=NULL;
        a->prev=NULL;
        p->next = a;
        a->prev = p;
        return;

        }
        insert_last(p->next,x);




    }

    void pushfront(int x)
    {
        node *a=(node *) malloc(sizeof (node));
        a->prev=NULL;
        a->next=NULL;
        a->val=x;
        if(head==NULL)
        {
            head=a;
            tail=a;
        }
        else
        {
            head->prev=a;
            a->next= head;
            head=a;
        }
    }

    int popback()
    {
        if(head==NULL)
        {
            printf("pop function cannot be applied\n");
            return -1;
        }
        else if(tail->prev==NULL)
        {
            int n=tail->val;
            head=NULL;
            tail=NULL;
            return n;
        }
        else
        {
            int n=tail->val;
            tail=tail->prev;
            tail->next=NULL;
            return n;

        }
    }

    int popfront()
    {
        if(head==NULL)
        {
            printf("pop function cannot be applied\n");
            return -1;
        }
        else if(tail->prev==NULL)
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
            head->prev=NULL;
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


main()
{
    linklist l;
    l.printlist();
    l.insert_last(l.head,6);
    l.printlist();
    l.insert_last(l.head,5);
    l.printlist();
    l.insert_last(l.head,12);
    l.printlist();


   /* l.printlist();
    l.pushfront(2);
    l.printlist();
    l.pushfront(3);
    l.printlist();
    l.pushfront(4);
    l.printlist();
    l.pushfront(5);
    l.printlist();
    l.pushfront(6);
    l.printlist();
    l.popback();
    l.popfront();
    l.printlist();
    l.popfront();
    l.popfront();
    l.popfront();
    l.printlist();*/
}
