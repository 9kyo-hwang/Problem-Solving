#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
  int N;
  scanf(" %d", &N);

  char arr[N + 1][3];
  for (int i = 1; i <= N; ++i) {
    scanf(" %c %c %c", &arr[i][0], &arr[i][1], &arr[i][2]);
    
    arr[i][0] -= '0';
    arr[i][1] -= '0';
    arr[i][2] -= '0';
  }

  int dp[N + 1][3];
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= N; ++i) {
    dp[i][0] = arr[i][0] + max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][1] = arr[i][1] + max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    dp[i][2] = arr[i][2] + max(dp[i - 1][1], dp[i - 1][2]);
  }

  printf("%d ", max({dp[N][0], dp[N][1], dp[N][2]}));
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= N; ++i) {
    dp[i][0] = arr[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
    dp[i][1] = arr[i][1] + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    dp[i][2] = arr[i][2] + min(dp[i - 1][1], dp[i - 1][2]);
  }

  printf("%d ", min({dp[N][0], dp[N][1], dp[N][2]}));

  return 0;
}