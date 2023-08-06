#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  int x, y;
  int max_sum = -2000000, min_sum = 2000000, max_diff = -2000000, min_diff = 2000000;
  while(N--) {
    cin >> x >> y;
    
    max_sum = max(max_sum, x + y);
    min_sum = min(min_sum, x + y);

    max_diff = max(max_diff, x - y);
    min_diff = min(min_diff, x - y);
  }

  cout << max(max_sum - min_sum, max_diff - min_diff);

  return 0;
}