#include <cstdio>

int main() {
  int N, M;
  scanf(" %d %d", &N, &M);

  int table[N + 1][N + 1];
  for (int i = 0; i <= N; ++i) {
    table[i][0] = table[0][i] = 0;
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      int num;
      scanf(" %d", &num);

      table[i][j] =
          table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1] + num;
    }
  }

  while (M--) {
    int x1, y1, x2, y2;
    scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);

    int interval_sum = table[x2][y2] - (table[x2][y1 - 1] + table[x1 - 1][y2]) +
                       table[x1 - 1][y1 - 1];
    printf("%d\n", interval_sum);
  }
  
  return 0;
}