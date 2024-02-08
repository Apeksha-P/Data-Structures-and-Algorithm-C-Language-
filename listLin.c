#include<stdio.h>
#include<stdlib.h>
typedef int dataList;
typedef int Position;
typedef enum {FALSE,TRUE}Boolean;
typedef struct listNode{
    dataList data;
    struct listNode *next;
}ListNode;
typedef struct{
    int count;
    Boolean full;
    ListNode * head;
}List;
void createList(List *l){
    l->count = 0;
    l->full = FALSE;
    l->head = NULL;
}
Boolean isFull(const List * l){
    return (l->full);
}
Boolean isEmpty(const List *l){
    return (l->head==NULL);
}
int listSize(const List *l){
    return (l->count);
}
//make list node
ListNode * MakeListNode(dataList x){
    ListNode * p = (ListNode * )malloc(sizeof(ListNode));
    if(p){
        p->data = x;
        p->next = NULL;
    }
    return (p);
}
//set Position
void setPosition(Position p,List *l,ListNode ** current){
    int count;
    ListNode *q;
    if(p<0||p>=l->count){
        printf("POsition not i ₮ the list");
    }
    else{
        q=l->head;
        for(count=1;count<=p;count++){
            q=q->next;
        }
        *current=q;
    }
}
void insertList(Position p,dataList x,List *l){
    ListNode*newNode = NULL, *current = NULL;
    if(p<0||p>listSize(l)){
        printf("position not in list");
    }
    else{
        newNode = MakeListNode(x);
        if(newNode == NULL){
            l->full=TRUE;
            printf("Not enough memoty");
        }
        else{
            if(p==0){
                newNode->next=l->head;
                l->head=newNode;
            }
            else{
                setPosition(p-1,l,&current);
                newNode->next=current->next;
                current->next=newNode;
            }
            l->count++;
            printf("%d insert\n",x);
        }
    }
}
int main(){
    int p,x;
    List l;
    createList(&l);
    do
    {
        printf("Enter position : ");
        scanf("%d",&p);
        printf("Enter value : ");
        scanf("%d",&x);
        insertList(p,x,&l);
    } while (1);
    return 0;
}