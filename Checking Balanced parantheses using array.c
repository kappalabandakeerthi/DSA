#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 20
int top=-1;
char parentheses[maxsize];
char balanced[maxsize];
int IsFull(){
    return top==maxsize-1;
}
int IsEmpty(){
    return top==-1;
}
void push(char ch){
    if(!IsFull()){
        balanced[++top]=ch;
    }
}
char pop(){
    if(!IsEmpty()){
        return balanced[top--];
    }
}
int main(){
    char p;
    int m=0;
    printf("Enter parentheses to check if balanced:");
    scanf("%s",parentheses);
    for(int i=0;i<strlen(parentheses);i++){
        if(parentheses[i]=='('||parentheses[i]=='['||parentheses[i]=='{'){
            push(parentheses[i]);
           }
        else if(parentheses[i]==')'||parentheses[i]==']'||parentheses[i]=='}'){
            if(parentheses[i]==')' && !IsEmpty()){
                if(pop()!='('){
                    m=-1;
                    break;
                }
            }
            if(parentheses[i]==']' && !IsEmpty()){
                if(pop()!='['){
                    m=-1;
                    break;
                }
            }
            if(parentheses[i]=='}' && !IsEmpty()){
                if(pop()!='{'){
                    m=-1;
                    break;
                }
            }
    }
 }
 if(m==-1){
    printf("Not balanced Parentheses\n");
 }
 else{
    printf("Balanced parentheses");
 }
    return 0;
}
