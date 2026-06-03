#include <stdio.h>
#include <stdlib.h>
#define maxsize 4
int queue[maxsize];
int f=-1,r=-1;
int IsEmpty(){
    return f==-1;
}
int IsFull(){
    return r==maxsize-1;
}
void enqueue(int x){
    if(IsFull()){
        printf("Maximum priority queue is Full \n");
    }
    else if(IsEmpty()){
        f++;
        queue[++r]=x;
    }
    else{
        r++;
        int i=r;
        while(i>f && x>queue[i-1]){
            queue[i]=queue[i-1];
            i--;
        }
        queue[i]=x;
    }
}
int dequeue(){
    if(IsEmpty()){
        printf("Maximum priority queue is Empty \n");
        return -1;
    }
    else if(f==r){
        int q=queue[f];
        f=-1;
        r=-1;
        return q;
    }
    else{
        return queue[r--];
    }
}
void display(){
    if(IsEmpty()){
        printf("Maximum priority queue is empty \n");
    }
    else{
        printf("elements are :");
        for(int i=f;i<=r;i++){
            printf("%d",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    int n,a;
    while(1){
        printf("1.Enqueue 2.Dequeue 3.Display else exit :");
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
