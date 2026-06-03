#include <stdio.h>
#include <stdlib.h>
void bfs(int n,int cost[][n],int u,int s[]){
    int q[n],f=0,r=0;
    s[u]=1;
    q[r++]=u;
    while(f<r){
        u=q[f++];
        for(int i=0;i<n;i++){
            if(cost[u][i]==1 && s[i]==0){
                    s[i]=1;
                    q[r++]=i;
            }
        }
    }
}
int main(){
    int n;
    printf("Enter no.of elements :");
    scanf("%d",&n);
    int cost[n][n],s[n];
    printf("Enter adjacency matrix elements :");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        s[i]=0;
    }
    bfs(n,cost,0,s);
    for(int i=0;i<n;i++){
        if(s[i]==0){
            printf("Graph is not connected \n");
            return 0;
        }
    }
    printf("Graph is connected \n");
    return 0;
}
