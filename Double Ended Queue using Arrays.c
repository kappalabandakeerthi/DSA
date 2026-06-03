#include <stdio.h>
#include <stdlib.h>
#define maxsize 3
int f=-1,r=-1;
int queue[maxsize];
int IsFull(){
    return r==maxsize-1;
}
int IsEmpty(){
    return (f==-1 && r==-1);
}
void enqueuef(int x){
    if(IsFull()){
        printf("Queue is Full \n");
    }
    else if(f==-1 && r==-1){
        r++;
        queue[++f]=x;
    }
    else{
        queue[--f]=x;
    }
}
void enqueuer(int x){
    if(IsFull()){
        printf("Queue is full \n");
    }
    else if(f==-1 && r==-1){
        f++;
        queue[++r]=x;
    }
    else{
        queue[++r]=x;
    }
}
int dequeuef(){
    if(IsEmpty()){
        printf("Queue is Empty \n");
        return -1;
    }
    else if(f==r){
        int q=queue[f];
        f=-1;
        r=-1;
        return q;
    }
    else{
        return queue[f++];
    }
}
int dequeuer(){
    if(IsEmpty()){
        printf("Queue is Empty \n");
    }
    else if(f==r){
        int q=queue[r];
        f=-1;
        r=-1;
    }
    else{
        return queue[r--];
    }
}
void display(){
    if(IsEmpty()){
        printf("Queue is Empty \n");
    }
    else{
        printf("Elements are :");
        for(int i=f;i<=r;i++){
            printf("%d",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    int n,a;
    while(1){
        printf("Enter 1.Enqueuef 2.Enqueuer 3.Dequeuef 4.Dequeuer 5.Display else exit :");
        scanf("%d",&n);
        switch(n){
    case 1:
        printf("Enter element to enqueue from Front :");
        scanf("%d",&a);
        enqueuef(a);
        break;
    case 2:
        printf("Enter element to enqueue from Rear :");
        scanf("%d",&a);
        enqueuer(a);
        break;
    case 3:
        dequeuef();
        break;
    case 4:
        dequeuer();
        break;
    case 5:
        display();
        break;
    default:
        exit(0);
        }
    }
    return 0;
}
