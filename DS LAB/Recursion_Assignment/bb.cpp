#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    node* left;
    node* right;
};

struct BST
{
    int elements = 0;
    node* root = NULL;
    void insert(node* rt, int val)
    {
        node* temp = new node;
        temp->data = val;
        temp->left=temp->right=NULL;


        if(root == NULL)
        {
            root = temp;
            return;
        }

        else if(rt == NULL)
        {
            rt = temp;
            return;
        }
        else
        {
            if(val<=rt->data)
            {
                if(rt->left==NULL) rt->left=temp;
                else insert(rt->left,val);
            }
            else
            {
                if(rt->right==NULL) rt->right=temp;
                else insert(rt->right,val);
            }
        }



    }


    void inorder(node* rt)
    {
        if(root==NULL)
        {
            cout<<"Empty Tree"<<endl;
            return;
        }
        if(rt==NULL)
        {
            return;
        }
        else
        {
            inorder(rt->left);
            cout<<rt->data<<" ";
            inorder(rt->right);
        }

    }


    void preorder(node* rt)
    {
        if(root==NULL)
        {
            cout<<"Empty Tree"<<endl;
            return;
        }
        if(rt==NULL)
        {
            return;
        }
        else
        {
            cout<<rt->data<<" ";
            preorder(rt->left);
            preorder(rt->right);
        }

    }



    void postorder(node* rt)
    {
        if(root==NULL)
        {
            cout<<"Empty Tree"<<endl;
            return;
        }
        if(rt==NULL)
        {
            return;
        }
        else
        {
            postorder(rt->left);
            postorder(rt->right);
            cout<<rt->data<<" ";
        }

    }

    int search(node* rt, int val)
    {
        if(rt == NULL) return 0;
        else
        {
            if(val==rt->data) return 1 + search(rt->left,val);
            else if(val<rt->data) return search(rt->left,val);
            else if(val>rt->data) return search(rt->right,val);

        }

    }


    node* dlt(node* rt, int val)
    {
        if(root == NULL)
        {
            cout<<"Empty Tree"<<endl;
            return root;
        }
        if(rt == NULL)
        {
            return rt;
        }



        if(val<rt->data)  rt->left = dlt(rt->left,val);
        if(val>rt->data)  rt->right = dlt(rt->right,val);

        if(val==rt->data)
        {
            if(root->left == NULL && root->right == NULL && root!=NULL) root = NULL;
            if(rt->left == NULL && rt->right == NULL) rt = NULL;
            else if(rt->left == NULL) rt = rt->right;
            else if(rt->right == NULL) rt = rt->left;
            else
            {
                node* temp = rt->left;
                while(temp->right!=NULL) temp=temp->right;
                rt->data = temp->data;
                rt->left = dlt(rt->left,temp->data);
            }
        }


        return rt;

    }





};


int main()
{
    BST b;
    int x;
    for(int i =0; i <3 ;i++)
    {
        cin>>x;
        b.insert(b.root,x);
        b.inorder(b.root);
        cout<<endl;
    }

    // cout<<"5 comes "<<b.search(b.root,5)<<" times "<<endl;
    for(int i = 0; i<3; i++)
    {
        cin>>x;
        b.dlt(b.root,x);
        b.inorder(b.root);
    }
    return 0;
}
