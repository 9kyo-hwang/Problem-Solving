#include <cstdio>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
  int n;
  scanf(" %d", &n);

  int triangle[n][n];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      scanf(" %d", &triangle[i][j]);
    }
  }

  int dp[n][n];
  dp[0][0] = triangle[0][0];

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][j];
      } else if (j == i) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = MAX(dp[i - 1][j - 1], dp[i - 1][j]);
      }

      dp[i][j] += triangle[i][j];
    }
  }

  int ans = -1;
  for (int j = 0; j < n; ++j) {
    ans = MAX(ans, dp[n - 1][j]);
  }
  
  printf("%d", ans);

  return 0;
}