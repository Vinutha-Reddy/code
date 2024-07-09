#include <stdio.h>
void Greedy(int n, int m, float p[], float w[]) {
  float profit = 0, max;
  int i, k, count;
  for (count = 0; count < n; count++) {
    max = 0;
    for (i = 0; i < n; i++) {
      if (p[i] / w[i] > max) {
        max = p[i] / w[i];
        k = i;
      }
    }
    if (w[k] <= m) {
      printf("\nItem %d selected with fraction 1", (k + 1));
      profit = profit + p[k];
      m = m - w[k];
      p[k] = 0;
    } else
      break;
  }
  printf("\nDiscrete knapsack profit=%f", profit);
  profit = profit + (m / w[k]) * p[k];
  printf(
      "\nContinuous knapsack profit by including %d item with fraction %f=%f\n",
      k+1, (m / w[k]), profit);
}
int main() {
  int n, m, i;
  float p[1000], w[1000];
  printf("\nEnter the number of items : ");
  scanf("%d", &n);
  printf("\nEnter the capacity of knapsack : ");
  scanf("%d", &m);
  printf("\nEnter the profit : ");
  for (i = 0; i < n; i++)
    scanf("%f", &p[i]);
  printf("\nEnter the weight : ");
  for (i = 0; i < n; i++)
    scanf("%f", &w[i]);
  Greedy(n, m, p, w);
}