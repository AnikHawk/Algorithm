#include<bits/stdc++.h>
using namespace std;

    struct student
{
    string name;
    int roll;
    int marks;
};
student a[100010];

struct Max_heap
{

//student a[100010];
    int last_index=0,p=0;

student c[100010];
    void Insert(student x)
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


    void print()
    {
        if(last_index==0)
        {
            printf("Heap is Empty!");
        }
        for(int i=1;i<=last_index;i++)
        {
            printf("%d ",a[i].marks);
        }
        printf("\n");
    }


    student delete_root()
    {
        if(last_index==0)
        {
            printf("Heap is Empty.Root can not be deleted\n");
            //return -1;
        }
        student x = a[1];
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
        int i,position = 1;
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
                if(c[i].marks!=c[i-1].marks)
                position++;
            }
            printf("Position: %d\n",position);
            cout<<c[i].name<< " ";
            printf(" Roll: %d Marks: %d\n",c[i].roll,c[i].marks);


        }
        printf("\n");


    /*   printf("In ascending oder: ");
        for(i=p-1;i>=0;i-- )
        {
            printf("%d ",c[i]);

        }
        printf("\n");
    }*/}
};



main(){
//BST b;
        student x;
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
       // b.insertt(b.Root,x);
        h.Insert(x);


        }

        //b.insertt(b.Root,name,roll,marks);

       // b.inorder(b.Root);

       h.heap_sort();

    }




