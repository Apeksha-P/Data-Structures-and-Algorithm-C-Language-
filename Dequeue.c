#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int queueEntry;
typedef enum {FALSE,TRUE} Boolean;
typedef struct dequeue{
    queueEntry item[MAXSIZE];
    int front;
    int rear;
    int count;
}Dequeue;
void createQueue(Dequeue *q){
    q->front=0;
    q->rear=-1;
    q->count=0;
}
Boolean isFull(const Dequeue *q){
    return (q->count==MAXSIZE);
}
Boolean isEmpty(const Dequeue *q){
    return (q->count==0);
}
void appendFront(queueEntry x,Dequeue *q){
    int i;
    if(isFull(q)){
        printf("Dequeue is Full");
        exit(1);
    }
    else{
        if(isEmpty(q)){
            q->item[q->front]=x;
            q->rear++;
        }
        else{
            if(q->front==0){
                for(i=q->rear;i>=q->front;i--){
                    q->item[q->rear+1]=q->item[q->rear];
                }
                q->rear++;
                q->item[q->front]=x;
            }
            else{
                q->item[--(q->front)]=x;
            }

        }
    }
    q->count++;
}
void appendRear(queueEntry x,Dequeue *q){
    if(isFull(q)){
        printf("Stack is full");
        exit(1);
    }
    else{
        q->item[++(q->rear)]=x;
        q->count++;
    }
}
int serveRear(queueEntry *x,Dequeue *q){
    if(isEmpty(q)){
        printf("Dequeue is Empty.");
        exit(1);
    }
    else{
        *x=q->item[(q->rear)--];
        q->count--;
    }
    return *x;
}
void serveFront(queueEntry *x,Dequeue *q){
    if(isEmpty(q)){
        printf("Dequeue is empty.");
        exit(1);
    }
    else{
        *x=q->item[(q->front)++];
        q->count--;
    }
}
void sort(int arr[],int count){
    int i,j,temp;
    for(i=0;i<count;i++){
        for(j=0;j<count-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted Dequeque : ");
    for(i=0;i<count;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
int main(){
    int y,i,x,count=0;

    Dequeue q;
    createQueue(&q);
    do
    {
        printf("Select 1 : Appent front\n ");
        printf("Select 2 : Appent rear\n ");
        printf("Select 3 : Serve front\n ");
        printf("Select 4 : Serve rear\n ");
        printf("Select 5 : Sort Dequeue\n ");
        printf("Select 6 : Exit\n ");
        scanf("%d",&y);
        switch (y)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d",&x);
            appendFront(x,&q);
            count++;
            break;
        case 2:
            printf("Enter value : ");
            scanf("%d",&x);
            appendRear(x,&q);
            count++;
            break;
        case 3:
            serveFront(&x,&q);
            count--;
            break;
        case 4:
            serveRear(&x,&q);
            count--;
            break;
        case 5:
            if (count > 0) {
                int arr[count];
                for (i = 0; i < count; i++) {
                    arr[i] = serveRear(&x, &q);
                }
                sort(arr, count);
                for (i = count - 1; i >= 0; i--) {
                    appendFront(arr[i], &q);
                }
            } else {
                printf("Deque is empty. Cannot sort.\n");
            }
            break;
        case 6:
        default:
            exit(1);
            break;
        }
    } while (1);

    return 0;
}
