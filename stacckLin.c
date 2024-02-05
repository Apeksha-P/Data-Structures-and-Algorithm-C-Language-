#include<stdio.h>
#include<stdlib.h>
typedef int stackEntry;
typedef struct node
{
    stackEntry entry;
    struct node * next;
}Node;
typedef enum {FALSE,TRUE} Boolean;
typedef struct
{
   int no_ele;
   Boolean full;
   Node * top;
}Stack;
void createStack(Stack *s){
    s->top=NULL;
    s->no_ele=0;
    s->full=FALSE;
}
Boolean isFull(const Stack*s){
    return (s->full);
}
Boolean isEmpty(const Stack*s){
    return (s->top==NULL);
}
void push(stackEntry x,Stack *s){
    Node *np;
    if(isFull(s)){
        printf("Stack is full");
        exit(1);
    }
    else{
        np = (Node*)malloc(sizeof(Node));
        np->entry=x;
        np->next=s->top;
        s->top=np;
        s->no_ele++;
    }
}
int pop(stackEntry *x,Stack *s){
    int y;
    Node*np;
    if(isEmpty(s)){
        printf("Stack is Empty");
        exit(1);
    }
    else{
        *x=s->top->entry;
        y = *x;
        np=s->top;
        s->top=s->top->next;
        s->no_ele--;
        free(np);
    }
    return y;
}
void sort(int *arr,int count){
    int temp,i,j;
    for(i=0;i<count;i++){
        for(j=0;j<count-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
    printf("Sorted Array : ");
    for(i=0;i<count;i++){
        printf("%d   ",arr[i]);
    }
    printf("\n");


}
int main(){
    int item,d,count=0,i;
    int arr[count];
    Stack s;
    createStack(&s);
    do
    {
        printf("Select 1: push element ");
        printf("\nSelect 2: pop element ");
        printf("\nSelect 3: sort stack ");
        printf("\nSelect 4: Exit\n");
        scanf("%d",&d);
        switch (d){
        case 1:
            printf("Enter value: ");
            scanf("%d",&item);
            push(item,&s);
            count++;
            break;
        case 2:
            pop(&item,&s);
            count--;
            break;
        case 3:
            if(count>0){
                int *arr = (int *)malloc(count*sizeof(int));
                for(i=0;i<count;i++){
                    arr[i]=pop(&item,&s);
                }
                sort(arr,count);
                for(i=0;i<count;i++){
                    push(arr[i],&s);
                }
                free(arr);
            }
            else{
                printf("Can not sorted\n");
            }
            break;
        case 4:
        default:
            break;
        }
    } while (1);


}
