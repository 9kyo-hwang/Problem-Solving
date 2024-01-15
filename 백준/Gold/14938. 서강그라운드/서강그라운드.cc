#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, r;
  cin >> n >> m >> r;

  vector<int> items(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> items[i];
  }

  vector dp(n + 1, vector(n + 1, INF));
  for (int i = 1; i <= n; ++i) {
    dp[i][i] = 0;
  }

  for (int i = 1; i <= r; ++i) {
    int a, b, l;
    cin >> a >> b >> l;

    dp[a][b] = dp[b][a] = l;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    for (int j = 1; j <= n; ++j) {
      if (dp[i][j] <= m) {
        sum += items[j];
      }
    }
    ans = max(ans, sum);
  }

  cout << ans;

  return 0;
}