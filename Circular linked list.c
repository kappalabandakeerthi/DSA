#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
struct node *prev=NULL;
struct node *new_node=NULL;
void create_node(int val){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=NULL;
}
void insert_beg(int val){
    create_node(val);
    if(head==NULL){
        head=new_node;
        head->next=head;
    }
    else{
        new_node->next=head;
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    head=new_node;
}
void insert_end(int val){
    create_node(val);
    if(head==NULL){
        head=new_node;
        head->next=head;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=head;
    }
}
void delete_beg(){
    if(head==NULL){
        printf("Circular linked list is empty \n");
    }
    else if(head->next==head){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=head->next;
        head=head->next;
        free(temp);
        temp=NULL;
    }
}
void delete_end(){
    if(head==NULL){
        printf("Circular linked list is empty \n");
    }
    else if(head->next==head){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        prev=NULL;
        while(temp->next!=head){
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
        free(temp);
        temp=NULL;
    }
}
void search(int val){
    if(head==NULL){
        printf("Circular linked list is empty \n");
    }
    else if(head->next==head){
        if(head->data==val){
            printf("Element found \n");
        }
        else{
            printf("Element not found \n");
        }
    }
    else{
        temp=head;
        int v=0;
        while(temp->next!=head && temp->data!=val){
            temp=temp->next;
            if(temp->data==val){
                v=1;
            }
        }
        if(v==0){
            printf("Element not found \n");
        }
        else{
            printf("Element found \n");
        }
    }
}
void display(){
    if(head==NULL){
        printf("Circular linked list is empty \n");
    }
    else{
        printf("Elements are :");
        temp=head;
        do{
          printf("%d",temp->data);
          temp=temp->next;
        }while(temp!=head);
    }
    printf("\n");
}
int main(){
    int n,a;
    while(1){
        printf("Enter 1.insert at beginning 2 .insert at end 3.delete at beginning 4.delete at end 5.search 6.display :");
        scanf("%d",&n);
        switch(n){
    case 1:
        printf("Enter element to insert at beginning :");
        scanf("%d",&a);
        insert_beg(a);
        break;
    case 2:
        printf("Enter element to insert at end :");
        scanf("%d",&a);
        insert_end(a);
        break;
    case 3:
        delete_beg();
        break;
    case 4:
        delete_end();
        break;
    case 5:
        printf("Enter element to search :");
        scanf("%d",&a);
        search(a);
        break;
    case 6:
        display();
        break;
    default:
        exit(0);
        }
    }
}
