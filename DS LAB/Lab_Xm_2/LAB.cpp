 #include<bits/stdc++.h>
using namespace std;

struct info
{
        string name;
        int roll;
        int marks;
};

struct BST
{
    struct node
    {
        info in;
        node* right;
        node* left;
    };
   // int element=0;
    node* Root= NULL;


    void insertt(node* root,info x)
    {

        if(root==NULL)
        {

            node* a = (node*) malloc(sizeof(node));
           // a->name = n;
           // a->roll = r;
           // a->marks = m;
            a->in = x;

            a->left = NULL;
            a->right = NULL;
            root = a;
            if(Root==NULL) Root=a;
           // element++;
            return;
        }

        else if(x.name > root->in.name)
        {
            if(root->right==NULL)
            {
                node* a = (node*) malloc(sizeof(node));
               // a->name = n;
                //a->roll = r;
                //a->marks = m;
                a->in = x;
                a->left = NULL;
                a->right = NULL;
                root->right = a;
                return;
            }

            else insertt(root->right,x);

        }

        else if(x.name<=root->in.name)
        {
            if(root->left==NULL)
            {
                node* a = (node*) malloc(sizeof(node));
                //a->name = n;
               // a->roll = r;
               // a->marks = m;
                a->in = x;
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
        //cout<<root->val<<"  ";
        cout<<"Name: "<<root->in.name;
        printf(" Roll: %d Marks: %d\n",root->in.roll,root->in.marks);
        inorder(root->right);

    }

    }


};

struct Max_heap
{
    info a[100010],c[100010];
    int last_index=0,p=0;

    void Insert(info x)
    {
        last_index++;
        a[last_index]=x;
        shift_down(last_index);

    }

    void shift_down(int i)
    {
        if(i<=1) return;

        if(a[i].marks>a[i/2].marks)
        {
            swap(a[i],a[i/2]);
            shift_down(i/2);
        }
        else return;
    }





    info delete_root()
    {

        info x = a[1];
        a[1]=a[last_index];
        last_index--;
        check(1);
        return x;

    }

    void check(int i)
    {
        if(i*2>last_index) return;
        if(i*2==last_index)
        {
            if(a[i].marks<a[2*i].marks)
            {
                swap(a[i],a[2*i]);

            }
            return;
        }
        if(a[i].marks<a[2*i].marks || a[i].marks<a[(2*i)+1].marks)
        {
            if(a[2*i].marks>a[(2*i)+1].marks)
            {
                swap(a[i],a[2*i]);
                check(2*i);
            }
            else
            {
                swap(a[i],a[(2*i)+1]);
                check((2*i)+1);
            }
        }
        else return;
    }


    void heap_sort()
    {
        int i,position=1;
        for(i=last_index;i>=1;i--)
        {
           // printf("%d ",delete_root());
           c[p] = delete_root();
           p++;
        }
        printf("In descending oder: ");
        for(i=0;i<p;i++ )
        {
            if(i!=0)
            {
               // if(c[i].marks!=c[i-1].marks)
                position++;
            }
            printf("Position: %d\n",position);
            cout<<"Name: "<<c[i].name;
            printf(" Roll: %d Marks: %d\n",c[i].roll,c[i].marks);


        }
        printf("\n");



    }
};

    main()

    {
        BST b;
        info x;
        Max_heap h;

        string name;
        int roll,marks,i,j,n,l;
         char line[200],tem;
         FILE *fp;
        char *input_file = "input.txt";
         fp=fopen(input_file,"r");
      //  freopen("input.txt","r",stdin);
          fscanf(fp,"%d",&n);
          fscanf(fp,"%c",&tem); //for new line


        for(i=0;i<n;i++)
        {
           // cin>>x.name;
           //scanf("%d %d",&x.roll, &x.marks);
           //b.insertt(b.Root,x);
           // h.Insert(x);
           fgets(line,200,fp);
        l=strlen(line);
        line[l-1]='\0';
        x.name=line;
        fscanf(fp,"%d",&x.roll);
        fscanf(fp,"%d",&x.marks);
        fscanf(fp,"%c",&tem); //for new line
        b.insertt(b.Root,x);
        h.Insert(x);


        }

        //b.insertt(b.Root,name,roll,marks);

        b.inorder(b.Root);

       h.heap_sort();

    }

