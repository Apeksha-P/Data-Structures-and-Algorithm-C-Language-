#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
typedef int queueEntry;
typedef enum {FALSE,TRUE} Boolean;
typedef struct queue
{
    queueEntry item[MAXSIZE];
    int rear;
    int front;
    int count;
}Queue;
void createQueue(Queue *q){
    q->count=0;
    q->front=0;
    q->rear=-1;
}
Boolean isEmpty(const Queue *q){
    return (q->count==0);
}
Boolean isFull(const Queue *q){
    return (q->count==MAXSIZE);
}
void Append(queueEntry x,Queue *q){
    if(isFull(q)){
        printf("Queue is full.");
        exit(1);
    }
    else{
        q->rear=(q->rear+1)%MAXSIZE;
        q->item[(q->rear)]=x;
        q->count++;
    }
}
int serve(queueEntry *x,Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty.");
        exit(1);
    }
    else{
        *x=q->item[(q->front)];
        q->front=(q->front+1)%MAXSIZE;
        q->count--;
    }
    return *x;
}
void sort(int arr[],int count){
    int i,j,temp;
    for ( i = 0; i < count; i++)
    {
        for ( j = 0; j < count-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
    }
    printf("Sort circular queue : ");
    for ( i = 0; i < count; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
    
    
}
int main(){
    int y,i,x,count=0;
    int arr[count];
    Queue q;
    createQueue(&q);
    do
    {
        printf("Select 1: Append element\n");
        printf("Select 2: serve element\n");
        printf("Select 3: sort dequeue\n");
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
            serve(&x,&q);
            count--;
            break;
        case 3:
            for(i=0;i<count;i++){
                arr[i]=serve(&x,&q);
            }
            sort(arr,count);
            for ( i = 0; i < count; i++)
            {
                Append(arr[i],&q);
            }
            break;
        case 4:   
        default:
            exit(1);
            break;
        }
    } while (1);
    
    return 0;
}