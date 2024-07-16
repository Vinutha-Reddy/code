#include<stdio.h>
int i,j,v,n,cost[10][10],dist[10];
int minm(int m,int n){
    return ((m<n)?m:n);
}
void Dijkstra(int source){
    int s[10]={0};
    int min,w=0;
    for(i=0;i<n;i++)
        dist[i]=cost[source][i];
    dist[source]=0;
    s[source]=1;
    for(i=0;i<n;i++){
        min=999;
        for(j=0;j<n;j++){
            if((s[j]==0)&&(min>dist[j])){
                min=dist[j];
                w=j;
            }
        }
        s[w]=1;
    for(v=0;v<n;v++){
        if(s[v]==0&&cost[w][v]!=999)
            dist[v]=minm(dist[v],dist[w]+cost[w][v]);
    }
    }
}
int main(){
    int source;
    printf("\n Enter the number of vertices : ");
    scanf("%d",&n);
    printf("\n Enter the cost matrix : ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    }
    printf("\n Enter the source vertex : ");
    scanf("%d",&source);
    Dijkstra(source);
    printf("\n The shortest distance is ...");
    for(i=0;i<n;i++)
        printf("Cost from %d to %d is %d \n",source,i,dist[i]);
}