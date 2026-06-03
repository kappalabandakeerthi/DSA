#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    int coeff;
    struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
struct node *temp=NULL;
struct node *temp1=NULL;
struct node *temp2=NULL;
struct node *new_node=NULL;
void create_node(int val,int coeff){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->coeff=coeff;
    new_node->next=NULL;
}
void insert1(int val,int coeff){
    create_node(val,coeff);
    if(head1==NULL){
        head1=new_node;
    }
    else{
        temp=head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void insert2(int val,int coeff){
    create_node(val,coeff);
    if(head2==NULL){
        head2=new_node;
    }
    else{
        temp=head2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void insert3(int val,int coeff){
    create_node(val,coeff);
    if(head3==NULL){
        head3=new_node;
    }
    else{
        temp=head3;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void add(){
    temp1=head1;
    temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->coeff==temp2->coeff){
            insert3(temp1->data+temp2->data,temp1->coeff);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->coeff>temp2->coeff){
            insert3(temp1->data,temp1->coeff);
            temp1=temp1->next;
        }
        else{
            insert3(temp2->data,temp2->coeff);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        insert3(temp1->data,temp1->coeff);
            temp1=temp1->next;
    }
    while(temp2!=NULL){
        insert3(temp2->data,temp2->coeff);
            temp2=temp2->next;
    }


}
void display(struct node *head){
    if(head==NULL){
        printf("Empty \n");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%dX^%d  ",temp->data,temp->coeff);
            temp=temp->next;
        }
    }
    printf("\n");
}
int main(){
    insert1(2,3);
    insert1(4,2);
    insert1(1,1);

    insert2(2,2);
    insert2(4,1);
    insert2(1,0);
    add();
    display(head3);
    return 0;
}
