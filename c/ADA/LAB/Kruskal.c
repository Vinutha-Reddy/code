/*1. Design and implement C/C++ Program to find Minimum Cost Spanning Tree of a given connected 
undirected graph using Kruskal's algorithm. */
#include <stdio.h>
int cost[10][10], n;

void kruskal() {
  int par[n];
  int a = 0, b = 0, u = 0, v = 0, min, mincost = 0, ne = 0;
  for (int i = 0; i < n; i++)
    par[i] = -1;

  printf("the minimum spanning tree edges are...");
  while (ne < n - 1) {

    min = 999;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (cost[i][j] < min) {
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }

    while (par[u] != -1)
      u = par[u];
    while (par[v] != -1)
      v = par[v];

    if (u != v) {
      printf("\nFrom vertex %d to vertex %d and the cost = %d\n", a, b, min);
      mincost += min;
      par[v] = u;
      ne++;
    }

    cost[a][b] = cost[b][a] = 999;
  }
  printf("Cost of MST = %d", mincost);
}
void main() {
  printf("Enter the no. of vertices:");
  scanf("%d", &n);
  printf("Enter the cost matrix\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &cost[i][j]);
  kruskal();
}

/*OUTPUT:
Enter the no. of vertices:5
Enter the cost matrix
999 5 999 6 999
5 999 1 3 999
999 1 999 4 6
6 3 4 999 2
999 999 6 2 999
the minimum spanning tree edges are...
From vertex 1 to vertex 2 and the cost = 1
From vertex 3 to vertex 4 and the cost = 2
From vertex 1 to vertex 3 and the cost = 3
From vertex 0 to vertex 1 and the cost = 5
Cost of MST = 11
*/