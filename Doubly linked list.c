#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
struct node *new_node=NULL;
void create_node(int val){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->prev=NULL;
    new_node->next=NULL;
    new_node->data=val;
}
void insert_beg(int val){
    create_node(val);
    if(head==NULL){
        head=new_node;
    }
    else{
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
    }
}
void insert_end(int val){
    create_node(val);
    if(head==NULL){
        head=new_node;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;
    }
}
void insert_pos(int val,int pos){
    if(pos==0){
        insert_beg(val);
        return;
    }
    else if(head==NULL){
        create_node(val);
        head=new_node;
        return;
    }
    else{
        create_node(val);
        temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next->prev=new_node;
        temp->next=new_node;
    }
}

void delete_beg(){
    if(head==NULL){
        printf("Doubly linked list  is empty \n");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
}
void delete_end(){
    if(head==NULL){
        printf("Doubly linked list  is empty \n");
    }
    else{
        temp=head;
        struct node *prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        temp=NULL;
    }
}
void search(int val){
    temp=head;
    while(temp!=NULL && temp->data!=val){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found \n");
    }
    else{
        printf("Element found \n");
    }
}
void delete_pos(int pos){
    if(head==NULL){
        printf("Doubly linked list is empty \n");
    }
    else if(pos==0){
        delete_beg();
    }
    else{
        temp=head;
        struct node *prev=NULL;
        for(int i=0;i<pos;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next->prev=prev;
        free(temp);
        temp=NULL;
    }
}
void delete_val(int val){
    if(head==NULL){
        printf("Doubly linked list is empty \n");
    }
    else{
        temp=head;
        int count=0;
        while(temp!=NULL && temp->data!=val){
                count++;
                temp=temp->next;
        }
        if(temp==NULL){
            printf("Element not found \n");
        }
        else{
            delete_pos(count);
        }
    }
}
void display(){
    if(head==NULL){
        printf("Doubly linked list is empty \n");
    }
    else{
        printf("Elements are :");
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    int n,a,pos;
    while(1){
        printf("Enter 1.insert at beginning 2.insert at end 3.insert at position 4.delete at beginning 5.delete at end 6.search an element 7.delete node by value 8.display the contents :");
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
        printf("Enter element to insert at position :");
        scanf("%d",&a);
        printf("Enter position :");
        scanf("%d",&pos);
        insert_pos(a,pos);
        break;
    case 4:
        delete_beg();
        break;
    case 5:
        delete_end();
        break;
    case 6:
        printf("Enter element to search :");
        scanf("%d",&a);
        search(a);
        break;
    case 7:
        printf("Enter element to delete :");
        scanf("%d",&a);
        delete_val(a);
        break;
    case 8:
        display();
        break;
    default:
        exit(0);
        }
    }
    return 0;
}
