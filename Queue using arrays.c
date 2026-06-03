#include <stdio.h>
#include <stdlib.h>
#define maxsize 3
int queue[maxsize];
int f=-1;
int r=-1;
int queue[maxsize];
int IsFull(){
    return r==maxsize-1;
}
int IsEmpty(){
    return f==-1;
}
void enqueue(int x){
    if(IsFull()){
        printf("Queue Full\n");
    }
    else if(f==-1 && r==-1){
        f++;
        queue[r++]=x;
    }
    else{
        queue[r++]=x;
    }
}
int dequeue(){
    if(IsEmpty()){
        printf("Queue is Empty \n");
    }
    else if(f==r){
        int q=queue[f];
        f=-1;
        r=-1;
    }
    else{
        return queue[f++];
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
        printf("1.Enqueue 2.Dequeue 3.Display :");
        scanf("%d",&n);
        switch(n){
    case 1:
        printf("Enter element to enqueue :");
        scanf("%d",&a);
        enqueue(a);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    default:
        exit(0);
        }
    }
    return 0;
}
