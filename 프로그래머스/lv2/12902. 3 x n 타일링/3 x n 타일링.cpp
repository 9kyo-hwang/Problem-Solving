#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<long long> dp(n + 1, 0);
  dp[2] = 3;

  for(int i = 4; i <= n; i += 2) {
    dp[i] = dp[i - 2] * dp[2]; // 1. 직전 단계에 dp[2]를 덧붙이는 경우
    for(int j = i - 4; j >= 2; j -= 2) {
      dp[i] += dp[j] * 2; // 2. 전전 단계부터 각 단계의 경우의 수에 그 단계의 특수 문양을 덧붙이는 경우
    }
    dp[i] += 2; // 해당 단계의 특수 문양 2가지 경우
      dp[i] %= 1'000'000'007;
  }
    
    return dp[n];
}