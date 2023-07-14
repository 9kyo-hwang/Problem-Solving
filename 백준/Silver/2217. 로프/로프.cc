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

  vector<int> counts(10001, 0);
  for(int n = 0; n < N; n += 1) {
    int w;
    cin >> w;

    counts[w] += 1;
  }

  int max_weight = 0;
  for(int i = 1; i <= 10000; i += 1) {
    for(int j = 0; j < counts[i]; j += 1) {
      max_weight = max(max_weight, i * N);
      N -= 1;
    }
  }

  cout << max_weight;

  return 0;
}