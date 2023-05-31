#include <iostream>
#include <vector>

using namespace std;

#define T true
#define F false
#define NIL nullptr

int main() {
  ios_base::sync_with_stdio(F);
  cin.tie(NIL);
  cout.tie(NIL);
  
  int n;
  cin >> n;
  
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = 3;
  
  for(int i = 3; i <= n; i++)
    dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
  
  cout << dp[n];
  
  return 0;
}