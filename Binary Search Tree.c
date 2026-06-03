#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *create_node(int val){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void insert(struct node *root,struct node *temp){
    if(temp->data < root->data){
        if(root->left!=NULL){
            insert(root->left,temp);
        }
        else{
            root->left=temp;
        }
    }
    else{
        if(root->right!=NULL){
            insert(root->right,temp);
        }
        else{
            root->right=temp;
        }
    }
}
struct node* delete(struct node* root,int val){
    if(root->data == val){
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        else if(root->right==NULL){
            struct node *temp=root;
            root=root->left;
            free(temp);
            temp=NULL;
        }
        else if(root->left==NULL){
            struct node *temp=root;
            root=root->right;
            free(temp);
            temp=NULL;
        }
        else{
            struct node *temp=root;
            while(temp->left!=NULL){
                temp=temp->right;
            }
            root->data=temp->data;
            free(temp);
            temp=NULL;
        }
    }
    else if(val < root->data){
        delete(root->left,val);
    }
    else{
        root->right=delete(root->right,val);
    }
    return root;
}
void *search(struct node *root,int val){
    if(root==NULL){
        return NULL;
    }
    else{
        if(root->data==val){
            return root;
        }
        else{
            if(val<root->data){
                search(root->left,val);
            }
            else{
                search(root->right,val);
            }
        }
    }
}
int main(){
    int n,a;
    while(1){
        printf("1.insert 2.preorder 3.inorder 4.postorder 5.search an element 6.Delete an element else exit :");
        scanf("%d",&n);
        switch(n){
    case 1:
        printf("Enter element to insert into BST :");
        scanf("%d",&a);
        struct node *temp=create_node(a);
        if(root==NULL){
            root=temp;
        }
        else{
            insert(root,temp);
        }
        break;
    case 2:
        preorder(root);
        printf("\n");
        break;
    case 3:
        inorder(root);
        printf("\n");
        break;
    case 4:
        postorder(root);
        printf("\n");
        break;
    case 5:
        printf("Enter element to be searched: ");
        scanf("%d",&a);
        struct node *tem=search(root,a);
        if(tem==NULL){
            printf("Element not found \n");
        }
        else{
            printf("Element found \n");
        }
        break;
    case 6:
        printf("Enter element to delete :");
        scanf("%d",&a);
        delete(root,a);
        break;
    default:
        exit(0);
        }
    }
    return 0;
}
