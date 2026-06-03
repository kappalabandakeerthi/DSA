#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 3
int result[maxsize+1];
struct node{
    int data;
    struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *temp=NULL;
struct node *temp1=NULL;
struct node *temp2=NULL;
struct node *new_node=NULL;
void create_node(int val){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=NULL;
}
void insert1_end(int val){
    create_node(val);
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
void insert2_end(int val){
    create_node(val);
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
void add(){
    if(head1==NULL && head2==NULL){
        return;
    }
    else if(head1==NULL || head2==NULL){
            return;
    }
    else{
        temp1=head1;
        temp2=head2;
        int p1,p2,sum=0,i=0;
        while(temp1!=NULL || temp2!=NULL){
            if(temp1!=NULL){
                p1=temp1->data;
            }
            else{
                p1=0;
            }
            if(temp2!=NULL){
                p2=temp2->data;
            }
            else{
                p2=0;
            }
            sum=p1+p2;
            result[i]=sum;
            i++;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }

}
int main(){
    char s1[maxsize+1],s2[maxsize+1];
    int n1,n2;
    printf("Enter 1st number :");
    scanf("%s",s1);
    printf("Enter 2nd number :");
    scanf("%s",s2);
    for(int i=0;i<strlen(s1);i++){
        int n=s1[i]-'0';
        insert1_end(n);
    }
    for(int i=0;i<strlen(s2);i++){
        int n=s2[i]-'0';
        insert2_end(n);
    }
    add();
    printf("Sum :");
    int carry=0;
    for(int i=maxsize;i>0;i--){
            result[i]+=carry;
            carry=result[i]/10;
            result[i]=result[i]%10;
    }
    for(int i=0;i<maxsize;i++){
        printf("%d ",result[i]);
    }
    return 0;
}
