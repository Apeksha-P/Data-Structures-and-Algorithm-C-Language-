#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef enum {FALSE,TRUE} Boolean;
typedef int queueEntry;
typedef struct queue
{
    queueEntry item[MAXSIZE];
    int front;
    int rear;
    int count;
} Queue;
void createQueue(Queue *q)
{
    q->count =0;
    q->front=0;
    q->rear=-1;
}
Boolean isFull(Queue *q)
{
    return(q->rear==MAXSIZE-1);
}
Boolean isEmpty(Queue *q)
{
    return(q->front>q->rear);
}
void Append(queueEntry x,Queue *q)
{
    if(isFull(q))
    {
        printf("Queue is Full");
        exit(1);
    }
    else
    {
        q->item[++(q->rear)]=x;
        q->count++;
    }
}
int Serve(queueEntry *x,Queue *q)
{
    int y;
    if(isEmpty(q))
    {
        printf("Queue is Empty");
    }
    else
    {
        *x=q->item[(q->front)++];
        y=*x;
        q->count--;
    }
    return y;
}
void sort(int arr[],int count)
{
    int i,j,temp;
    for(i=0; i<count; i++)
    {
        for(j=0; j<count-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sort array : ");
    for(i=0; i<count; i++)
    {
        printf("%d  ",arr[i]);
    }
}
int main()
{
    int y,x,i,count=0;
    int arr[count];
    Queue q;
    createQueue(&q);
    do
    {
        printf("Select 1: Append element");
        printf("\nSelect 2: Serve element");
        printf("\nSelect 3: Sort Queue");
        printf("\nSelect 4: Exit\n");
        scanf("%d",&y);
        switch (y)
        {
        case 1:
            printf("Enter Append value: ");
            scanf("%d",&x);
            Append(x,&q);
            count++;
            break;
        case 2:
            Serve(&x,&q);
            count--;
            break;
        case 3:
            for(i=0; i<count; i++)
            {
                arr[i]=Serve(&x,&q);
            }
            sort(arr,count);
            for(i=0; i<count; i++)
            {
                Append(x,&q);
            }
        case 4:
        default:
            exit(1);
            break;
        }
    }
    while (1);

    return 0;
}
