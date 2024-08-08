/*3. b. Design and implement C/C++ Program to find the transitive closure using Warshal's 
algorithm. */
#include<stdio.h>
int i,j,k;
void Warshal(int a[][10],int n){
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
}
int main(){
    int n,adj[10][10];
    printf("\n Enter the number of vertices : ");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix : ");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);
    Warshal(adj,n);
    printf("\n Transitive closure of the given graph is : ");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d",adj[i][j]);
        printf("\n");
    }
}