#include<bits/stdc++.h>
using namespace std;
struct tree
{
    struct node
{
    int val;
    node* left;
    node* right;
};
    node* root;

    tree()
    {
        root = NULL;
    }
    void insert(int x)
    {
        node* temp = (node *)malloc(sizeof(node));
        temp->val = x;
        temp->left = NULL;
        temp->right = NULL;

        if(root == NULL)
        {
            root = temp;
        }
        else
        {
            node* current_node = root;
            while(1)
            {
                if(x <= current_node->val)
                {
                    if(current_node->left == NULL)
                    {
                        current_node->left = temp;
                        return;
                    }
                    current_node = current_node->left;
                }
                else
                {
                    if(current_node->right == NULL)
                    {
                        current_node->right = temp;
                        return;
                    }
                    current_node = current_node->right;
                }
            }
        }
    }
    void inorder(node* temp)
    {
        if(temp==NULL) return;
        inorder(temp->left);
        printf("%d ",temp->val);
        inorder(temp->right);
    }
    void postorder(node* temp)
    {
        if(temp==NULL) return;
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->val);
    }
    int search (node* temp,int x)
    {
        if(temp==NULL) return 0;
        if(x <= temp->val)
        {
            int p = 0;
            if(temp->val == x)
                {
                    p = 1;
                }
            return p + search(temp->left,x);
        }
        else
        {
            return search(temp->right,x);
        }
    }
    node* del(node* temp, int x)
    {
        if(temp==NULL)
            {
                printf("Element can not be found\n");
                return temp;
            }
        else if(x < temp->val)
        {
            temp->left = del(temp->left,x);
        }
        else if(x > temp->val)
        {
            temp->right = del(temp->right,x);
        }
        else
        {
            if(temp->left==NULL && temp->right==NULL)
                temp = NULL;
            else if(temp->left == NULL)
                temp = temp->right;
            else if(temp->right == NULL)
                temp = temp->left;
            else
            {
                node*temp2 = leftmost(temp->right);
                temp ->val = temp2 ->val;
                temp->right = del(temp->right,temp->val);
            }
            printf("Deletion Successful\n");
            return temp;
        }
    }
    node *leftmost(node *x)
    {
        if(x->left==NULL) return x;
        else return leftmost(x->left);
    }

};
int main ()
{
    tree T;
    int i,x;
    printf("\n\n                               *****Binary Search Tree*****\n\n");
    printf("                                    1. Insert\n");
    printf("                                    2. Delete\n");
    printf("                                    3. In-order Traverse\n");
    printf("                                    4. Post-order Traverse\n");
    printf("                                    5. Search\n\n");
    while(scanf("%d",&x)==1)
    {
        if(x==1)
        {
            printf("Enter a value to insert\n");
            scanf("%d",&i);
            T.insert(i);
        }
        else if(x==2)
        {
            if(T.root==NULL)
            {
                printf("No elements in tree\n");
                continue;
            }
            printf("Enter a value to delete\n");
            scanf("%d",&i);
            T.del(T.root,i);
        }
        else if(x==3)
        {
            if(T.root==NULL)
            {
                printf("No elements in tree\n");
                continue;
            }
            printf("In-Order Traverse ");
            T.inorder(T.root);
            printf("\n");
        }
        else if(x==4)
        {
            if(T.root==NULL)
            {
                printf("No elements in tree\n");
                continue;
            }
            printf("Post-Order Traverse ");
            T.postorder(T.root);
            printf("\n");
        }
        else if(x==5)
        {
            if(T.root==NULL)
            {
                printf("No elements in tree\n");
                continue;
            }
            printf("Enter a value to search\n");
            scanf("%d",&i);
            int f = T.search(T.root,i);
            printf("%d is found %d time",i,f);
            if(f>1)
                printf("s");
            printf(".\n");
        }
    }
}




 node* dlt(node* rt, int val)
    {
        if(root == NULL)
        {
            cout<<"Empty Tree"<<endl;
            return root;
        }

        if(root->left == NULL && root->right == NULL && root!=NULL && root->val == x)
        {
            root = NULL;
            return root;
        }
        if(rt == NULL)
        {
            printf("Could not find the element to be deleted\n")
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

