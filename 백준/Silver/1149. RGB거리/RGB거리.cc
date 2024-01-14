#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector costs(N, vector(3, 0));
  for (auto &cost : costs) {
    for (auto &color : cost) {
      cin >> color;
    }
  }

  vector dp(N, vector(3, 0));
  dp[0] = costs[0];

  for (int i = 1; i < N; ++i) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
  }

  cout << min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});

  return 0;
}