#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
int cqueue[maxsize];
int f=-1,r=-1;
int IsFull(){
    return f==(r+1)%maxsize;
}
int IsEmpty(){
    return (f==-1 && r==-1);
}
void enqueue(int x){
    if(IsFull()){
        printf("Circular Queue is Full \n");
    }
    else if(f==-1 && r==-1){
        f=(f+1)%maxsize;
        r=(r+1)%maxsize;
        cqueue[r]=x;
    }
    else{
        r=(r+1)%maxsize;
        cqueue[r]=x;
    }
}
int dequeue(){
    if(IsEmpty()){
        printf("Circular Queue is Empty \n");
        return -1;
    }
    else if(f==r){
        int q=cqueue[f];
        f=-1;
        r=-1;
        return q;
    }
    else{
        int q=cqueue[f];
        f=(f+1)%maxsize;
        return q;
    }
}
void display(){
    if(IsEmpty()){
        printf("Circular Queue is Empty \n");
    }
    else{
        printf("Elements are :");
        int i=f;
        do{
            printf("%d",cqueue[i]);
            i=(i+1)%maxsize;
        }while(i!=(r+1)%maxsize);
        printf("\n");
    }
}
int main(){
    int n,a;
    while(1){
        printf("Enter 1.Enqueue 2.Dequeue 3.Display else exit :");
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
