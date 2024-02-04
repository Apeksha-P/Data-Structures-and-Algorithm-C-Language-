#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int stackEntry;
typedef struct
{
    int top;
    stackEntry entry[MAXSIZE-1];
} Stack;
typedef enum {FALSE,TRUE} Boolean;
Boolean isFull(const Stack *s)
{
    return (s->top==MAXSIZE-1);
}
Boolean isEmpty(const Stack *s)
{
    return (s->top==-1);
}
void createStack(Stack *s)
{
    s->top=-1;
}
void push(stackEntry x,Stack *s)
{
    if(isFull(s))
    {
        printf("Stack is full");
        exit(1);
    }
    else
    {
        s->entry[++(s->top)]=x;
    }
}
int pop(stackEntry *x,Stack *s)
{
    int y;
    if(isEmpty(s))
    {
        printf("Stack is empty");
        exit(1);
    }
    else
    {
        *x=s->entry[s->top--];
        y = *x;
    }
    return y;
}
int main()
{
    int popItem,y,p,d,i,temp,j,count=0;
    int arr[MAXSIZE];
    Stack s;
    createStack(&s);
    do
    {
        printf("\nSelect 1: push element ");
        printf("\nSelect 2: pop element ");
        printf("\nSelect 3: Sort stack");
        printf("\nSelect 4: Exit \n");
        scanf("%d",&y);
        switch(y)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d",&p);
            push(p,&s);
            arr[count]=p;
            count++;
            break;
        case 2:
            p=pop(&popItem,&s);
            count--;
            printf("pop %d",p);
            break;
        case 3:
            for(i=count-1; i>=0; i--)
            {
                arr[i] = pop(&popItem,&s);
            }
            for(i=0; i<count-1; i++)
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
            printf("Stack Array: ");
            for(i=0; i<count; i++)
            {
                printf("%d  ",arr[i]);
            }
            for(i=0; i<count; i++)
            {
                push(arr[i],&s);
            }
            break;
        case 4:
        default:
            exit(1);
        }
        /*if(y==1)
        {
            printf("Enter value: ");
            scanf("%d",&p);
            push(p,&s);
            arr[count]=p;
            count++;
        }
        else
        {
            if(y==2)
            {
                pop(&popItem,&s);
            }
            else
            {
                do
                {
                    if(y==3)
                    {
                        for(i=count-1;i>=0;i--){
                            arr[i] = pop(&popItem,&s);
                        }
                        for(i=0; i<count-1; i++)
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
                        for(i=0; i<count; i++)
                        {
                            printf("\t%d",arr[i]);
                        }
                        for(i=0;i<count;i++){
                            push(arr[i],&s);
                        }
                        exit(1);

                    }
                    else
                    {
                        exit(1);
                    }
                }
                while(1);
                //exit(1);
            }
        }*/
    }
    while(1);


    return 0;
}
