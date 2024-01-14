#include <cstdio>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
  int T;
  scanf(" %d", &T);

  while (T--) {
    int n;
    scanf(" %d", &n);

    int sticker[2][n + 1];
    for (int i = 0; i < 2; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf(" %d", &sticker[i][j]);
      }
    }

    int dp[2][n + 1];
    dp[0][0] = dp[1][0] = 0;
    dp[0][1] = sticker[0][1], dp[1][1] = sticker[1][1];

    for (int j = 2; j <= n; ++j) {
      dp[0][j] = MAX(dp[1][j - 1], dp[1][j - 2]) + sticker[0][j];
      dp[1][j] = MAX(dp[0][j - 1], dp[0][j - 2]) + sticker[1][j];
    }

    printf("%d\n", MAX(dp[0][n], dp[1][n]));
  }

  return 0;
}