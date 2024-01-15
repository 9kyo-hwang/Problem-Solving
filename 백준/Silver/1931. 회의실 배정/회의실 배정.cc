#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<pii> v(N);
  for (auto &[end, begin] : v) {
    cin >> begin >> end;
  }

  sort(v.begin(), v.end());

  int end = -1, count = 0;
  for (const auto &[e, b] : v) {
    if (b >= end) {
      end = e;
      count += 1;
    }
  }

  cout << count;

  return 0;
}