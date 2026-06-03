#include <stdio.h>
#include <stdlib.h>
void dfs(int n,int a[][n],int u,int s[]){
    s[u]=1;
    for(int i=0;i<n;i++){
        if(a[u][i]==1 && s[i]==0){
            dfs(n,a,i,s);
        }
    }
}
int main(){
    int n;
    printf("Enter no.of elements :");
    scanf("%d",&n);
    int cost[n][n],s[n];
    printf("Enter elements of adjacency matrix :");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        s[i]=0;
    }
    dfs(n,cost,0,s);
    for(int i=0;i<n;i++){
        if(s[i]==0){
            printf("Graph is not connected \n");
            return 0;
        }
    }
    printf("Graph is connected \n");
    return 0;
}
