#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 15
#define FULL MAXSIZE
#define EMPTY 0
typedef int Position;
typedef float listItem;
typedef enum {FALSE,TRUE} Boolean;

//define list
typedef struct{
    listItem entry[MAXSIZE];
    int count;
}List;

//create list
void createList(List *l){
    l->count=0;
}

//Check list is full
Boolean isFull(const List *l){
    return (l->count == FULL);
}

//check list is empty
Boolean isEmpty(const List *l){
    return (l->count==EMPTY);
}

//insert last to list
void insertLast(listItem x,List *l){
    if(isFull(l)){
        printf("List is full\n");
        exit(1);
    }
    else{
        l->entry[l->count]=x;
        l->count++;
    }
}

//find list size
int listSize(List *l){
    return(l->count);
}

//Sort list
int sort(listItem *x,List *l){
    int i,temp,j;
    if(isEmpty(l)){
        printf("List is Empty");
        exit(1);
    }
    else{
        for(i=0;i<=listSize(l)-2;i++){
            for(j=0;j<=listSize(l)-i-2;j++){
                if(l->entry[j]>l->entry[(j+1)]){
                    temp=l->entry[j];
                    l->entry[j]=l->entry[(j+1)];
                    l->entry[(j+1)]=temp;
                }
            }

        }
        printf("Sort values : ");
        for(i=0;i<listSize(l);i++){
            printf("%.1f  ",l->entry[i]);
        }
        printf("\n");
    }
}

//retrive from list
//Find mean and variance
void mean(Position p,listItem *x,List *l){
    int i;
    float sum=0,mean,minV,z=0,var;
    if(isEmpty(l)){
        printf("List is Empty\n");
        exit(1);
    }
    else{
        if(p<0||p>listSize(l)){
            printf("position is not in list\n");
            exit(1);
        }
        else{
                for(i=0;i<p;i++){
                    sum= sum+(l->entry[i]);
                }
                mean = sum/p;
                printf("Mean = %.2f\n",mean);
                for(i=0;i<p;i++){
                    minV = l->entry[i]-mean;

                    z = z+(minV * minV);
                }
                var = z/p;
                printf("Variance = %.2f\n",var);
        }
    }
}
//travell list
void travelList(const List *l){
    int i;
    for(i=0;i<listSize(l);i++){
       printf("%.1f ",l->entry[i]);
    }
    printf("\n");
}
int main(){
    int y,p;
    float x;
    List l;
    createList(&l);
    do{
        printf("Select 1 : Enter value to List\n");
        printf("Select 2 : Display List\n");
        printf("Select 3 : Sort value\n");
        printf("Select 4 : Find mean and variance\n");
        printf("Select 5 : Exit\n");
        scanf("%d",&y);
        switch(y){
        case 1:
             printf("Enter real number : ");
             scanf("%f",&x);
             insertLast(x,&l);
             break;
        case 2:
            travelList(&l);
            break;
        case 3:
            sort(&x,&l);
            break;
        case 4:
            printf("Enter position you want to find mean : ");
            scanf("%d",&p);
            mean(p,&x,&l);
            break;
        case 5:
        defualt :
            exit(1);
        }

    }while(1);
    return 0;
}
