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

  vector<int> ropes(N, 0);
  for(auto &rope : ropes)
    cin >> rope;

  sort(ropes.begin(), ropes.end());

  int max_weight = 0;
  for(const auto &rope : ropes) {
    max_weight = max(max_weight, rope * N);
    N -= 1;
  }

  cout << max_weight;

  return 0;
}