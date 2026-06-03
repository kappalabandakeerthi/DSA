#include <stdio.h>
#include <stdlib.h>
struct node{
    int row,col,data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
struct node *new_node=NULL;
void create_node(int row,int col,int val){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->row=row;
    new_node->col=col;
    new_node->data=val;
    new_node->next=NULL;
}
void insert(int r,int c,int v){
    create_node(r,c,v);
    if(head==NULL){
        head=new_node;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void display(){
    if(head==NULL){
        printf("Matrix is empty \n");
    }
    else{
        printf("Elements are :\n");
        temp=head;
        while(temp!=NULL){
            printf("%d %d %d \n",temp->row,temp->col,temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
int main(){
    insert(0,1,2);
    insert(2,3,7);
    insert(3,2,1);

    display();
    return 0;
}
