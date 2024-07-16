#include<stdio.h>
int i,j,k;
int min(int a,int b){
    return a<b?a:b;
}
void Floyd(int d[][10],int n){
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}
int main(){
    int n,cost[10][10];
    printf("\n Enter the number of vertices : ");
    scanf("%d",&n);
    printf("\n Enter the cost matrix : ");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    Floyd(cost,n);
    printf("\n All pair shortest path : ");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d",cost[i][j]);
        printf("\n");
    }
}