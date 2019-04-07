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
    int i,flag=0,cnt=0;

    void insert_back(int x)
    {
        node *a = (node *) malloc(sizeof(node));
        a->val=x;
        a->next=head;


        if(head==NULL)
        {
            head=a;
            tail=a;

        }
        else
        {
            p=head;
            while(p!=tail)
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
            a->next=head;


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
        else if(head==tail)
        {
            head=NULL;
            tail=NULL;
        }

        else
        {
            p=head;
            while(p->next->next!=head)
            {
                p=p->next;
            }
            int n=p->next->val;
            p->next=head;
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
        else if(head==tail)
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
            while(p!=tail)
            {
                printf("%d ",p->val);
                p=p->next;
            }
            printf("%d\n",tail->val);
            //printf("\n");
        }
    }

    void traverse_from_head(int x)
    {
        for(p=head,i=1;;p=p->next,i++)
        {

            if(p->val==x)
            {
                printf("Found in node %d",i);
                flag=1;
            }
            if(p==tail) break;
        }
        if(flag==0) printf("Not found\n");
        flag=0;
    }


        void traverse_from_tail(int x)
    {
        for(p=tail,i=1;;p=p->next,i++)
        {

            if(p->val==x)
            {
                printf("Found in node %d",i);
                flag=1;
            }
            if(p->next==tail) break;
        }
        if(flag==0) printf("Not found\n");
        flag=0;
    }


    void josophus(int k,int n)
    {
        p=tail;
        while(1)
        {
            for(i=0;i<k-1;i++)
            {
                p=p->next;
            }
            p->next=p->next->next;
            head=p;
            tail=p->next->next;
            cnt++;
            if(cnt==n-1) break;
        }


        cnt=0;
    }



};




main()
{
    int n,k,j,x;
    linklist l;
    scanf("%d %d",&n,&k);

    for(j=0;j<n;j++)
    {
        scanf("%d",&x);
        l.insert_back(x);
    }
    l.printlist();

    l.josophus(k,n);
    printf("remains ");
    l.printlist();



}

