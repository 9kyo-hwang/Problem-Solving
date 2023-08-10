#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, k;
  cin >> N >> k;

  // B[k] = a -> a보다 작거나 같은 수가 최소 k개

  ll l = 1, r = k;
  ll answer = 0;
  while(l <= r) {
    ll m = (l + r) / 2;
    ll count = 0;

    for(int i = 1; i <= N && i <= m; i += 1) {
      count += min(m / i, N);
    }

    if(count >= k) { // 임의의 수 m보다 작은 수가 B[k]보다 많음
      r = m - 1;
      answer = m;
    } else {
      l = m + 1;
    }
  }

  cout << answer;

  return 0;
}