#include<stdio.h>
#include<stdlib.h>
typedef enum {FALSE,TRUE} Boolean;
typedef int queueEntry;
typedef struct node
{
    queueEntry item;
    struct node *next;
} Node;
typedef struct
{
    Node*front;
    Node*rear;
    int count;
    Boolean full;
} Queue;
void createQueue(Queue *q)
{
    q->count=0;
    q->front=q->rear=NULL;
    q->full=FALSE;
}
Boolean isFull(Queue *q)
{
    return (q->full);
}
Boolean isEmpty(Queue *q)
{
    return (q->front==NULL && q->rear==NULL);
}
void Append(queueEntry x,Queue *q)
{
    Node*np;
    if(isFull(q))
    {
        printf("Queue is full.");
        exit(1);
    }
    else
    {
        np=(Node*)malloc(sizeof(Node));
        np->item=x;
        np->next=NULL;
        if(isEmpty(q))
        {
            q->front=q->rear=np;
        }
        else
        {
            q->rear->next=np;
            q->rear=np;
        }
        q->count++;
    }
}
int Serve(queueEntry *x,Queue *q)
{
    int y;
    Node*np;
    if(isEmpty(q))
    {
        printf("Queue is empty.");
        exit(1);
    }
    else
    {
        *x=q->front->item;
        y=*x;
        np=q->front;
        q->front=q->front->next;
        q->count--;
        if (q->front==NULL)
        {
            q->rear=NULL;
        }
        free(np);
    }
    return y;
}
void sort(int arr[],int count)
{
    int i,j,temp;
    for(i=0; i<count; i++)
    {
        for(j=0; j<count-i-1; j++)
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
    printf("\n");
}
int main()
{
    int y,x,i,count=0;
    int arr[count];
    Queue q;
    createQueue(&q);
    do
    {
        printf("Select 1: Append value\n");
        printf("Select 2: serve value\n");
        printf("Select 3: Sort queue\n");
        printf("Select 4: Exit\n");
        scanf("%d",&y);
        switch (y)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d",&x);
            Append(x,&q);
            count++;
            break;
        case 2:
            Serve(&x,&q);
            count--;
            break;
        case 3:
            if(count>0)
            {
                int *arr = (int *)malloc(count*sizeof(int));
                for ( i = 0; i < count; i++)
                {
                    arr[i]=Serve(&x,&q);
                }
                sort(arr,count);
                for(i=0; i<count; i++)
                {
                    Append(x,&q);
                }
                free(arr);
            }
            else
            {
                printf("Can not sort.");
            }

            break;
        case 4:
        default:
            exit(1);
            break;
        }
    }
    while (1);


    return 0;
}
