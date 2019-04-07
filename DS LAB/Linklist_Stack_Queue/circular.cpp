#include<stdio.h>

struct queue
{
    int front=0,rear=0,i;
    int a[8];

    void enqueue(int x)
    {
      a[rear%8]=x;
      rear=(rear+1)%8;

    }

    int dequeue()
    {
        front=(front+1)%8;
        return a[(front-1)%8];
    }

    void print()
    {
      for(i=front;; i=(i+1)%8)
      {
          if(i==rear) break;
          printf("%d ",a[i]);
          //if(i==rear-1) break;

      }
      printf("\n");
    }
};

main()
{
    queue q;
    q.enqueue(1);
    q.print();
    q.enqueue(2);
    q.print();
    q.enqueue(3);
    q.print();
    q.enqueue(4);
    q.print();
    q.dequeue();

    q.print();

     q.dequeue();

    q.print();
    q.enqueue(1);
    q.print();
    q.enqueue(1);
    q.print();
     q.enqueue(1);
    q.print();
     q.enqueue(1);
    q.print();
    q.enqueue(2);
    q.print();
     q.dequeue();
    q.print();
    q.enqueue(5);
    q.print();



   printf("r %d\n",la[(rear+7)%8]);




}
