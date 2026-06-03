#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
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
    }
    else{
        new_node->next=head;
        head=new_node;
    }
}
void insert_end(int val){
    create_node(val);
    if(head==NULL){
        insert_beg(val);
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }

}
void insert_pos(int val,int pos){
    create_node(val);
    if(head==NULL){
        printf("Linked list is empty \n");
    }
    else if(pos==0){
        insert_beg(val);
    }
    else{
        temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        if(temp!=NULL){
            new_node->next=temp->next;
            temp->next=new_node;
        }
    }
}
void display(){
    if(head==NULL){
        printf("Linked list is empty \n");
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
void delete_beg(){
    if(head==NULL){
        printf("Linked list is empty \n");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
}
void delete_end(){
    if(head==NULL || head->next==NULL){
        delete_beg();
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
void delete_pos(int pos){
    if(head==NULL){
        printf("Linked list is empty \n");
    }
    else if(pos==0){
        delete_beg();
    }
    else{
        struct node *prev=NULL;
       temp=head;
       for(int i=0;i<pos;i++){
        prev=temp;
        temp=temp->next;
       }
       prev->next=temp->next;
       free(temp);
       temp=NULL;
    }
}
void delete_val(int val){
    if(head==NULL){
        printf("Linked list is empty can't be searched \n");
    }
    else{
        int pos=0;
        temp=head;
        while(temp!=NULL && temp->data!=val){
            pos++;
            temp=temp->next;
        }
    delete_pos(pos);
    }
}
void search(int val){
    if(head==NULL){
        printf("Linked list is empty \n");
    }
    else{
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
}
void count(){
        temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
    printf("The number of nodes are : %d \n",count);
}
void reverse(){
    if(head==NULL || head->next==NULL){
        return;
    }
    else{
        temp=head;
        struct node *next=NULL;
        struct node *prev=NULL;
        while(temp!=NULL){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        head=prev;
    }
}
void sort(){
    if(head==NULL || head->next==NULL){
        return;
    }
    else{
        struct node *prev=head;
        int d;
        temp=head->next;
        int sorted=0;
        do{
            sorted=0;
            prev=head;
            temp=head->next;
        while(temp!=NULL){
            if(prev ->data >= temp->data){
              d=prev->data;
              prev->data=temp->data;
              temp->data=d;
              sorted=1;
           }
           prev=temp;
           temp=temp->next;
        }
        }while(sorted);
    }
}
int main(){
    int n,a,pos,val;
    while(1){
        printf("1.insert at beginning 2.insert at end 3.insert by position \n 4.delete at beginning 5.delete at end 6.delete by value 7.delete by position \n 8.reverse 9.count 10.search an element 11.sort 12.display :");
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
        printf("Enter element to insert by postion :");
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
        printf("Enter element to delete :");
        scanf("%d",&a);
        delete_val(a);
        break;
    case 7:
        printf("Enter element position to delete :");
        scanf("%d",&pos);
        delete_pos(pos);
        break;
    case 8:
        reverse();
        break;
    case 9:
        count();
        break;
    case 10:
        printf("Enter element to search :");
        scanf("%d",&val);
        search(val);
        break;
    case 11:
        sort();
        break;
    case 12:
        display();
        break;
    default:
        exit(0);
        }
    }
    return 0;
}
