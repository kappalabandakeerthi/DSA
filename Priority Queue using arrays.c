#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
int queue[maxsize];
int f=-1,r=-1;
int IsFull(){
    return r==maxsize-1;
}
int IsEmpty(){
    return f==-1;
}
void enqueue(int x){
    if(IsFull()){
        printf("Minimum priority queue is full \n");
    }
    else if(IsEmpty()){
        f++;
        queue[++r]=x;
    }
    else{
        r++;
        int i=r;
        while(i>=f && x<queue[i-1]){
            queue[i]=queue[i-1];
            i--;
        }
        queue[i]=x;
    }
}
int dequeue(){
    if(IsEmpty()){
        printf("Minimum priority Queue is Empty \n");
        return -1;
    }
    else if(f==r){
        int m=queue[f];
        f=-1;
        r=-1;
        return m;
    }
    else{
        return queue[f++];
    }
}
void display(){
    if(IsEmpty()){
        printf("Minimum priority Queue is Empty \n");
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
    int a,b;
    while(1){
        printf("1.enqueue 2.dequeue 3.Display else exit :");
        scanf("%d",&a);
        switch(a){
    case 1:
        printf("Enter element to enqueue in minimum priority queue :");
        scanf("%d",&b);
        enqueue(b);
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
