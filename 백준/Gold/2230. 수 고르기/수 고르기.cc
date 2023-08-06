#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<int> v(N);
  for(int &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  int l = 0, r = 1;
  int min_diff = v.back() - v[l];
  while(l < N && r < N) {
    int m = v[r] - v[l];
    
    if(m >= M) {
      if(m < min_diff) {
        min_diff = m;
      }

      l += 1;
      if(l == r)
        r += 1;
    } else {
      r += 1;
    }
  }

  cout << min_diff;

  return 0;
}