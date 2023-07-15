#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> dp(N + 1);
  dp[0] = 0;

  for(int i = 1; i <= N; i += 1) {
    if(sqrt(i) == (int)sqrt(i)) { // 제곱수면 1
      dp[i] = 1;
    } else {
      dp[i] = i;
      for(int j = 1; j * j <= i; j += 1) { // 아니라면 i보다 작은 제곱수 + (i - 제곱수)의 경우의 수 합
        dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
      }
    }
  }

  cout << dp[N];

  return 0;
}