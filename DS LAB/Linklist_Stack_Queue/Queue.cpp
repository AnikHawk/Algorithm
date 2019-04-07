#include<stdio.h>

struct queue
{
    int front=0,rear=0,i;
    int a[100];

    void enqueue(int x)
    {
      a[rear]=x;
      rear++;

    }

    int dequeue()
    {
        front++;
        return a[front-1];
    }

    void print()
    {
      for(i=front;i<rear; i++)
      {

          printf("%d ",a[i]);


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
    q.enqueue(5);
    q.print();







}
