#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<ll> v(N);
  for(ll &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  ll answer = 0;
  if(N % 2 == 1) {
    answer = v.back();
    N -= 1;
  }

  for(int i = 0; i < N / 2; i += 1)
    answer = max(answer, v[i] + v[N - 1 - i]);

  cout << answer;

  return 0;
}