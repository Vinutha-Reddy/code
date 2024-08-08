/*5. Design and implement C/C++ Program to obtain the Topological ordering of vertices in a given 
digraph. */
#include<stdio.h>
int cost[10][10],n,indegree[10],i,j,k,count;
void Calculate_indegree(){
    for(i=0;i<n;i++){
        indegree[i]=0;
        for(j=0;j<n;j++)
            indegree[i]+=cost[j][i];
    }
}
void Source_removal(){
    int removed[10]={0};
    printf("Topological ordereing is : ");
    for(count=0;count<n;count++){
        Calculate_indegree();
        for(i=0;i<n;i++){
            if(removed[i]==0&&indegree[i]==0)
                break;
        }
        if(i==n){
            printf("Graph is cyclic");
            return;
        }
        printf("%d ",i);
        removed[i]=1;
        for(k=0;k<n;k++)
            cost[i][k]=0;
    }
}
int main(){
    printf("Enter the value of n : ");
    scanf("%d",&n);
    printf("Enter value of cost matrix : ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    }
    Source_removal();
}