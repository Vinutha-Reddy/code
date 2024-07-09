#include <stdio.h>
#include <stdlib.h>
void DpKnapsack(int n, int m, int p[], int w[]) {
  int v[n + 1][m + 1];
  int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      if (i == 0 || j == 0)
        v[i][j] = 0;
      else if (j < w[i])
        v[i][j] = v[i - 1][j];
      else
        v[i][j] = Max(v[i - 1][j], p[i] + v[i - 1][j - w[i]]);
      printf("%d\t", v[i][j]);
    }
    printf("\n");
  }
  printf("Optimal profit : %d\n", v[n][m]);
  printf("Selected items are :");
  while (m != 0) {
    if (v[n][m] != v[n - 1][m]) {
      printf("%d", n);
      m = m - w[n];
    }
    n--;
  }
}
int Max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  int i, n, p[100], w[100], m;
  printf("Enter the number of items : ");
  scanf("%d", &n);
  printf("Enter the capacity of knapscak : ");
  scanf("%d", &m);
  printf("Enter the profit : ");
  for (i = 1; i <= n; i++)
    scanf("%d", &p[i]);
  printf("Enter the weight : ");
  for (i = 1; i <= n; i++)
    scanf("%d", &w[i]);
  DpKnapsack(n, m, p, w);
}