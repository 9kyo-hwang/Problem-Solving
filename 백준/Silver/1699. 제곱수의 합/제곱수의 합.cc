#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> dp(N + 1, INT32_MAX);
  dp[0] = 0;

  for (int i = 1; i <= N; i += 1) {
    for (int j = 1; j * j <= i; j += 1) {
      dp[i] = min(dp[i], 1 + dp[i - j * j]);
    }
  }

  cout << dp[N];

  return 0;
}