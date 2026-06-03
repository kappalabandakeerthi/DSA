#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxsize 20
int top=-1,t=-1;
char stack[maxsize];
char infix[maxsize];
char postfix[maxsize];
int IsFull(){
    return top==maxsize-1;
}
int IsEmpty(){
    return top==-1;
}
void push(char ch){
    if(!IsFull()){
        stack[++top]=ch;
    }
}
char pop(){
    if(!IsEmpty()){
        return stack[top--];
    }
}
int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int i=0;
    printf("enter infix expression :");
    scanf("%s",infix);
    while(infix[i]!='\0'){
        if(isalnum(infix[i])){
            postfix[++t]=infix[i];
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while(stack[top]!='('){
                postfix[++t]=pop();
            }
            pop();
        }
        else{
            if(precedence(stack[top])<precedence(infix[i])){
                push(infix[i]);
            }
            else{
                while(precedence(stack[top])>=precedence(infix[i])){
                    postfix[++t]=pop();
                }
                push(infix[i]);
            }
        }
        i++;
    }
    while(top!=-1){
        postfix[++t]=pop();
    }
    postfix[++t]='\0';
    printf("Postfix expression is %s",postfix);
    return 0;
}
