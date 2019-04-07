#include<bits/stdc++.h>
using namespace std;


struct Max_heap
{
    struct student
    {
        string name;
        int marks;
        int roll;
    };

    student s[100010],c[100010];
    int last_index=0,p=0,n=0;

    void Insert(string iname,int iroll,int imarks)
    {
        last_index++;
        n++;
        s[last_index].name = iname;
        s[last_index].roll = iroll;
        s[last_index].marks = imarks;

        shift_down(last_index);

    }

    void shift_down(int i)
    {
        if(i<=1) return;

        if(s[i].marks>s[i/2].marks)
        {
            swap(s[i],s[i/2]);
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
            cout<<s[i].name;
            printf("   Roll: %d    Marks: %d\n",s[i].roll,s[i].marks);
        }
        //printf("\n");
    }


    student delete_root()
    {
        if(last_index==0)
        {
            student y;
            printf("Heap is Empty.Root can not be deleted\n");
            return y;
        }
        student x = s[1];
        s[1]=s[last_index];
        last_index--;
        check(1);
        return x;

    }

    void check(int i)
    {
        if(i*2>last_index) return;
        if(i*2==last_index)
        {
            if(s[i].marks<s[2*i].marks)
            {
                swap(s[i],s[2*i]);

            }
            return;
        }
        if(s[i].marks<s[2*i].marks || s[i].marks<s[(2*i)+1].marks)
        {
            if(s[2*i].marks>s[(2*i)+1].marks)
            {
                swap(s[i],s[2*i]);
                check(2*i);
            }
            else
            {
                swap(s[i],s[(2*i)+1]);
                check((2*i)+1);
            }
        }
        else return;
    }


    void heap_sort()
    {
        int pos = 1;
        int i;
        for(i=last_index;i>=1;i--)
        {
           // printf("%d ",delete_root());
          // c[p] = delete_root();
          // p++;
          delete_root();
        }
       // printf("In descending oder: ");
        for(i=n;i>=1;i-- )
        {
            if(i!=n)

            {
                if(s[i].marks!=s[i+1].marks) pos++;
            }
            printf("Position: %d\n",pos);
            cout<<"Name: "<<s[i].name;
            printf("  Roll: %d    Marks: %d\n",s[i].roll,s[i].marks);
            //if(s[i].marks!=s[i-1].marks) pos++;




        }
       // printf("\n");


       /* printf("In ascending oder: ");
        for(i=p-1;i>=0;i-- )
        {
           printf("Name: %s   Roll: %d    Marks: %d\n",c[i].name,c[i].roll,c[i].marks);

        }*/
       // printf("\n");
    }
};


struct BST
{
    struct node
    {
        string name;
        int marks;
        int roll;

        node* right;
        node* left;
    };
   // int element=0;
    node* Root= NULL;


    void insertt(node* root,string iname,int iroll,int imarks)
    {

        if(root==NULL)
        {

            node* a = (node*) malloc(sizeof(node));
            a->name = iname;
            a->roll = iroll;
            a->marks = imarks;
            a->left = NULL;
            a->right = NULL;
            root = a;
            if(Root==NULL) Root=a;
           // element++;
            return;
        }

        else if(iname > root->name)
        {
            if(root->right==NULL)
            {
                node* a = (node*) malloc(sizeof(node));
                a->name = iname;
                a->roll = iroll;
                a->marks = imarks;
                a->left = NULL;
                a->right = NULL;
                root->right = a;
                return;
            }

            else insertt(root->right,iname,iroll,imarks);

        }

        else if(iname <= root->name)
        {
            if(root->left==NULL)
            {
                node* a = (node*) malloc(sizeof(node));
                a->name = iname;
                a->roll = iroll;
                a->marks = imarks;
                a->left = NULL;
                a->right = NULL;
                root->left = a;
                return;
            }

            else insertt(root->left,iname,iroll,imarks);

        }
    }


    void inorder(node* root)
    {
        if (Root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }

    if(root==NULL) return;
    if (root != NULL)
    {

        inorder(root->left);
       // cout<<root->val<<"  ";
       cout<<"Name: "<<root->name;
       printf("Roll: %d    Marks: %d\n",root->roll,root->marks);
        inorder(root->right);

    }

    }



};



main()

{
    Max_heap h;
    BST b;
    string name;
    int roll,marks,i,j,n;
    freopen("input.txt","r",stdin);

    while(scanf("%d", &n)==1)
    {
       for(i=0;i<n;i++)
       {
           cin>>name;
           scanf("%d %d",&roll, &marks);
           b.insertt(b.Root,name,roll,marks);
           h.Insert(name,roll,marks);

       }
    }

    printf("*****************Inorder BST**************\n");
    b.inorder(b.Root);
    printf("*****************Heap Sort**************\n");
    h.heap_sort();


}
