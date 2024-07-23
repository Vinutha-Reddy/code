#include <math.h>
#include <stdio.h>
int i, j;
int place(int x[], int k) {
  for (i = 1; i < k; i++) {
    if ((x[i] == x[k]) || (abs(x[i] - x[k]) == abs(i - k)))
      return 0;
  }
  return 1;
}
int NQueen(int n) {
  int x[10], k, count = 0;
  k = 1;
  x[k] = 0;
  while (k != 0) {
    x[k]++;
    while ((x[k] <= n) && (!place(x, k)))
      x[k]++;
    if (x[k] <= n) {
      if (k == n) {
        printf("Solution : %d\t", ++count);
        for (i = 1; i <= n; i++) {
          for (j = 1; j <= n; j++)
            printf("%c", j == x[i] ? 'Q' : 'X');
          printf("\n");
        }
      } else {
        ++k;
        x[k] = 0;
      }
    } else
      k--;
  }
  return count;
}
void main() {
  int n;
  printf("\n Enter size of chessboard : ");
  scanf("%d", &n);
  printf("\n The number of possibilities are %d", NQueen(n));
}