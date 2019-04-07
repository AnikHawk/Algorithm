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

        }
        else
        {
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=a;

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


main()
{
    linklist l;
    int a[5]={1,2,3,4,5},i;
    for(i=0;i<5;i++) l.insert_back(a[i]);
    l.printlist();
    l.insert_front(37);
    l.printlist();
    l.delete_back();
    l.printlist();
    l.delete_front();
    l.printlist();
    l.delete_front();
    l.printlist();
    l.delete_front();
    l.printlist();
    l.delete_front();
    l.printlist();
    l.delete_front();
    l.printlist();
    l.delete_front();
    l.printlist();
    l.insert_front(5);
    l.printlist();
     l.insert_front(0);
    l.printlist();
    l.delete_back();
    l.printlist();


}
