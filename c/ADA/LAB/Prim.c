/*2. Design and implement C/C++ Program to find Minimum Cost Spanning Tree of a
given connected undirected graph using Prim's algorithm. */
#include <stdio.h>
int cost[10][10], n;
void prim() {
  int vt[10] = {0};
  int a = 0, b = 0, min, mincost = 0, ne = 0;

  vt[0] = 1;
  while (ne < n - 1) {
    min = 999;
    for (int i = 0; i < n; i++) {
      if (vt[i] == 1) {
        for (int j = 0; j < n; j++) {
          if (cost[i][j] < min && vt[j] == 0) {
            min = cost[i][j];
            a = i;
            b = j;
          }
        }
      }
    }

    printf("\nEdge from vertex %d to vertex %d and the cost %d", a, b, min);
    vt[b] = 1;
    ne++;
    mincost += min;
    cost[a][b] = cost[b][a] = 999;
  }
  printf("\nMinimum spanning tree cost is %d", mincost);
}
void main() {
  printf("Enter the no. of vertices: ");
  scanf("%d", &n);
  printf("Enter the cost matrix\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", &cost[i][j]);
  }
  prim();
}

/*OUTPUT:
Enter the no. of vertices: 5
Enter the cost matrix
999 5 999 6 999
5 999 1 3 999
999 1 999 4 6
6 3 4 999 2
999 999 6 2 999
Edge from vertex 0 to vertex 1 and the cost 5
Edge from vertex 1 to vertex 2 and the cost 1
Edge from vertex 1 to vertex 3 and the cost 3
Edge from vertex 3 to vertex 4 and the cost 2
minimum spanning tree cost is 11
*/