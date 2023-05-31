#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<vector<int>> dp(N + 1, vector<int>(11, 0));
  for (int j = 1; j <= 10; j++)
    dp[1][j] = j;

  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= 10; j++) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
    }
  }

  cout << dp[N][10];

  return 0;
}