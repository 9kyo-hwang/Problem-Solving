#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> counts(100001, 0);
  for(int n = 0; n < N; n += 1) {
    int t;
    cin >> t;

    counts[t] += 1;
  }

  ll max_tips = 0;
  int order = 1;
  bool flag = false;
  for(int i = 100000; i >= 1; i -= 1) {
    for(int j = 0; j < counts[i]; j += 1) {
      if(i - (order - 1) <= 0) {
        flag = true;
        break;
      }

      max_tips += i - (order - 1);
      order += 1;
    }

    if(flag) {
      break;
    }
  }

  cout << max_tips;
  return 0;
}