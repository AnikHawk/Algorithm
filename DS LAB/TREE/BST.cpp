#include<bits/stdc++.h>
using namespace std;


struct BST
{
    struct node
    {
        int val;
        node* right;
        node* left;
    };
   // int element=0;
    node* Root= NULL;


    void insertt(node* root,int x)
    {

        if(root==NULL)
        {

            node* a = (node*) malloc(sizeof(node));
            a->val = x;
            a->left = NULL;
            a->right = NULL;
            root = a;
            if(Root==NULL) Root=a;
           // element++;
            return;
        }

        else if(x>root->val)
        {
            if(root->right==NULL)
            {
                node* a = (node*) malloc(sizeof(node));
                a->val = x;
                a->left = NULL;
                a->right = NULL;
                root->right = a;
                return;
            }

            else insertt(root->right,x);

        }

        else if(x<=root->val)
        {
            if(root->left==NULL)
            {
                node* a = (node*) malloc(sizeof(node));
                a->val = x;
                a->left = NULL;
                a->right = NULL;
                root->left = a;
                return;
            }

            else insertt(root->left,x);

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
        cout<<root->val<<"  ";
        inorder(root->right);

    }

    }

    void preorder(node* root)
    {
        if (Root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }

    if(root==NULL) return;
    if (root != NULL)
    {
        cout<<root->val<<"  ";
        preorder(root->left);
        preorder(root->right);

    }

    }

    void postorder(node* root)
    {
        if (Root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }

    if(root==NULL) return;
    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<"  ";
    }

    }


    int Search(node* p,int x )
    {
        if(p==NULL) return 0;
        if(p->val <x) return 0+Search(p->right , x);
        if(p->val == x) return 1+Search(p->left , x);
        else return 0+ Search(p->left ,x);
    }




 node* Delete(node* p, int x)
    {

         if(Root == NULL)
     {
         printf("Tree is empty\n");
         return p;
     }



        else  if(Root->left == NULL && Root->right == NULL && Root!=NULL && Root->val == x)
        {
            Root = NULL;
            return Root;
        }

        else if(p==NULL)
        {
            printf("Element can not be found\n");
            return p;
        }

        else if(x < p->val)
        {
            p->left = Delete(p->left,x);
        }
        else if(x > p->val)
        {
            p->right = Delete(p->right,x);
        }
        else
        {
            if(p->left==NULL && p->right==NULL)
                p = NULL;
            else if(p->left == NULL)
                p = p->right;
            else if(p->right == NULL)
                p = p->left;
            else
            {
                node*temp = rightmost(p->left);
                p ->val = temp ->val;
                p->left = Delete(p->left,p->val);
            }
            //printf("Deletion Successful\n");
            return p;
        }
    }
    node *rightmost(node *y)
    {
        if(y->right==NULL) return y;
        else return rightmost(y->right);
    }



};


main()
{
    BST b;
    int n,x,y,i;

   while(1)
   {
       cin>>n;

       //Insert
       if(n==1)
       {
           printf("Write an element to be inserted: ");
           cin>>x;
           b.insertt(b.Root,x);
       }

       //Delete
       if(n==2)
       {
           printf("Write an element to be deleted: ");
           cin>>x;
           b.Root = b.Delete(b.Root,x);
       }


       //Inorder
       if(n==3)
       {

           printf("Inorder Traversal:\n");
           b.inorder(b.Root);
           printf("\n");
       }

       //preorder
        if(n==4)
       {

           printf("Preorder Traversal:\n");
           b.preorder(b.Root);
           printf("\n");
       }


       //postorder
        if(n==5)
       {

           printf("Postorder Traversal:\n");
           b.postorder(b.Root);
           printf("\n");
       }
   }


}
