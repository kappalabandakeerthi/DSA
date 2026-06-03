#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 50
int top=-1;
char str[maxsize];
char reverse[maxsize];
int IsFull(){
    return top==maxsize-1;
}
int IsEmpty(){
    return top==-1;
}
void push(char ch){
    if(!IsFull()){
        reverse[++top]=ch;
    }
}
char pop(){
    if(IsEmpty()){
        return '\0';
    }
    else{
        return reverse[top--];
    }
}
int main(){
    printf("Enter string :");
    scanf("%s",str);
    printf("Original String :%s \n",str);
    for(int i=0;i<strlen(str);i++){
        push(str[i]);
    }
    for(int i=0;i<strlen(str);i++){
        str[i]=pop();
    }
    printf("Reversed String : %s \n",str);
    return 0;
}
