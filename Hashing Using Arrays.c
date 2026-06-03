#include <stdio.h>
#define size 7
int table[size];
int hash(int key){
    return key%size;
}
void insert(int key){
    int index=hash(key);
    int i=index;
    if(table[index]==-1){
        table[index]=key;
    }
    else{
        i=(i+1)%size;
        while(i!=index){
            if(table[i]==-1){
                table[i]=key;
                break;
            }
            else{
                i=(i+1)%size;
            }
        }
        printf("Hash table is full \n");
    }
}
void search(int key){
    int index=hash(key);
    int i=index;
    if(table[index]==key){
        printf("element found \n");
        return;
    }
    else{
        i=(i+1)%size;
        while(i!=index){
            if(i==index){
                printf("Element not found \n");
                break;
            }
            else{
                if(table[i]==key){
                    printf("element found \n");
                    break;
                }
                else{
                    i=(i+1)%size;
                }
            }
        }
    }
    printf("Element not found \n");
}
void delete(int key){
    int index=hash(key);
    int i=index;
    if(table[index]==key){
        table[index]=-1;
        return;
    }
    else{
        i=(i+1)%size;
        while(i!=index){
            if(i==index){
                printf("Element not found \n");
                break;
            }
            else{
                if(table[i]==key){
                    table[i]=-1;
                    break;
                }
                else{
                    i=(i+1)%size;
                }
            }
        }
    }
    printf("Element not found \n");
}
void display(){
    for(int i=0;i<size;i++){
        if(table[i]!=-1){
            printf("%d ",table[i]);
        }
        else{
            printf("- ");
        }
    }
}
int main(){
    for (int i = 0; i < size; i++)
        table[i] = -1;

    insert(10);
    insert(20);
    insert(25);
    insert(28);

    printf("Hash Table:\n");
    display();

    printf("Deleting value 20\n");
    delete(20);
    display();

    printf("Searching value 10\n");
    search(10);

    printf("Searching value 0\n");
    search(0);

    return 0;
}
