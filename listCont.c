#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define FULL MAXSIZE
#define EMPTY 0
typedef int listEntry;
typedef int Position;
typedef enum {FALSE,TRUE} Boolean;
typedef struct{
    int count;
    listEntry entry[MAXSIZE];
}List;
void createList(List *l){
    l->count=0;
}
Boolean isEmpty(const List *l){
    return (l->count==EMPTY);
}
Boolean isFull(const List *l){
    return (l->count==FULL);
}
int listSize(const List *l){
    return (l->count);
}
void insertLast(listEntry x,List *l){
    if(isFull(l)){
        printf("List is full");
    }
    else{
        l->entry[l->count++]=x;
        printf("%d insert last\n",x);
    }
}
void insertList(Position p,listEntry x,List *l){
    int i;
    if(isFull(l)){
        printf("List is full");
        exit(1);
    }
    else{
        if(p<0||p>listSize(l)){
            printf("position not in the list\n");
        }
        else{
            for(i=listSize(l);i>=p;i--){
                l->entry[i+1]=l->entry[i];
            }
            l->entry[p]=x;
            l->count++;
            printf("%d Insert value\n",x);
        }
    }
}
void deleteList(Position p,listEntry *x,List *l){
    int i;
    if(isEmpty(l)){
        printf("List empty");
        exit(1);
    }
    else{
        if(p<0||p>listSize(l)){
            printf("Position not in the List");
            exit(1);
        }
        else{
            *x=l->entry[p];
            for(i=p;i<listSize(l);i++){
                l->entry[i]=l->entry[i+1];
            }
            l->count--;
        }
    }
}
void retriveList(Position p,listEntry *x,List *l){
    if(isEmpty(l)){
        printf("List is empty");
        exit(1);
    }
    else{
        if(p<0||p>listSize(l)){
            printf("Position is not in the list");
            exit(1);
        }
        else{
            *x=l->entry[p];
        }
    }
}
void replaceList(Position p,listEntry x,List *l){
    if(isEmpty(l)){
        printf("List is empty");
        exit(1);
    }
    else{
        if(p<0||p>listSize(l)){
            printf("%d replace",x);
            exit(1);
        }
        else{
            l->entry[p]=x;
        }
    }
}
void traverselList(const List *l){
    int i;
    for(i=0;i<listSize(l);i++){
        printf("%d ",l->entry[i]);
    }
}
void sort(List*l){
    int i,j,temp;
    printf("Sorted List : ");
    for(i=0;i<listSize(l);i++){
        for(j=0;j<listSize(l)-i-1;j++){
            if(l->entry[j]>l->entry[j+1]){
                temp=l->entry[j];
                l->entry[j]=l->entry[j+1];
                l->entry[j+1]=temp;
            }
        }
    }
    for(i=0;i<listSize(l);i++){
        printf("%d  ",l->entry[i]);
    }
    printf("\n");
}
int main(){
    int x,y,p;
    List l;
    createList(&l);
    do
    {
        printf("Select 1 : Insert Last\n");
        printf("Select 2 : Insert List\n");
        printf("Select 3 : Delete item\n");
        printf("Select 4 : Retrive item\n");
        printf("Select 5 : Replace item\n");
        printf("Select 6 : Traversel List\n");
        printf("Select 7 : Sort List\n");
        printf("Select 8 : Exit\n");
        scanf("%d",&y);
        switch (y)
        {
        case 1:
            printf("Enter item : ");
            scanf("%d",&x);
            insertLast(x,&l);
            break;
        case 2:
            printf("Enetr Item : ");
            scanf("%d",&x);
            printf("Enter position : ");
            scanf("%d",&p);
            insertList(p,x,&l);
            break;
        case 3:
            printf("Enter position : ");
            scanf("%d",&p);
            deleteList(p,&x,&l);
            break;
        case 4:
            printf("Enter position : ");
            scanf("%d",&p);
            retriveList(p,&x,&l);
            printf("%d\n",x);
            break;
        case 5:
            printf("Enter item : ");
            scanf("%d",&x);
            printf("Enter position : ");
            scanf("%d",&p);
            replaceList(p,x,&l);
            break;
        case 6:
            traverselList(&l);
            printf("\n");
            break;
        case 7:
            sort(&l);
            break;
        case 8:
        default:
            exit(1);
            break;
        }
    } while (1);
    return 0;
}