#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = int;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<ll> dp(N, 1), sequence(N);
  ll maximum = 0;
  for(int i = 0; i < N; i += 1) {
    cin >> sequence[i];
    for(int j = 0; j < i; j += 1) {
      if(sequence[i] > sequence[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    maximum = max(maximum, dp[i]);
  }

  cout << maximum;

  return 0;
}