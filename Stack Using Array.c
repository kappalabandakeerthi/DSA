#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define maxsize 3
int top=-1;
int stack[maxsize];
int IsFull(){
    return top==maxsize-1;
    }
int IsEmpty(){
    return top==-1;
    }
void push(int x){
    if(IsFull()){
            printf("Stack Overflow \n");
    } else{
        stack[++top]=x;
        }
    }
int pop(){
    if(IsEmpty()){
            printf("Stack Underflow\n");
            return -1;
    }
    else{
        return stack[top--];
    }
}
void peek(){
    if(IsEmpty()){
        printf("Stack Underflow\n");
    }
    else{
        printf("Top element of stack is %d \n",stack[top]);
    }
}
void display(){
    if(IsEmpty()){
            printf("stack Is Empty\n");
    }
    else{
        printf("Elements are :");
    for(int i=top;i>=0;i--){
            printf("%d",stack[i]);
    }
    printf("\n");
    }}
int main(){
    int n;
    while(1){
        printf("Enter 1.push 2.pop 3.peek 4.display :");
    scanf("%d",&n);
    switch(n){
    case 1:
        int m;
        printf("Enter element to push :");
        scanf("%d",&m);
        push(m);
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        break;
    case 4:
        display();
        break;
    default:
        exit(0);
    }
  }
    return 0;
}
