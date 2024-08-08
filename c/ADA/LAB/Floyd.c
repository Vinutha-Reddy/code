/*3. a. Design and implement C/C++ Program to solve All-Pairs Shortest Paths
problem using Floyd's algorithm. */
#include <stdio.h>
int i, j, k;
int min(int a, int b) {
  return a < b ? a : b;
}
void Floyd(int d[][10], int n) {
  for (k = 1; k <= n; k++) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
  }
}
int main() {
  int n, cost[10][10];
  printf("\n Enter the number of vertices : ");
  scanf("%d", &n);
  printf("\n Enter the cost matrix : ");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++)
      scanf("%d", &cost[i][j]);
  }
  Floyd(cost, n);
  printf("\n All pair shortest path : ");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++)
      printf("%d", cost[i][j]);
    printf("\n");
  }
}

/*OUTPUT:
Enter the number of vertices : 4
Enter the cost matrix :
999 8 4 999
999 999 1 999
4 999 999 999
999 2 9 999
All pair shortest path :
8 8 4 999
5 13 1 999
4 12 8 999
7 2 3 999
*/