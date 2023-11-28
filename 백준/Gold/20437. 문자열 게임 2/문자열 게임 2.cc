#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  vector<int> counts;

  while (T--) {
    string W;
    int K;
    cin >> W >> K;

    int strlen = W.length();

    counts.assign(26, 0);
    for (const char &ch : W) {
      counts[ch - 'a'] += 1;
    }

    int minlen = 10001, maxlen = 0;
    for (int l = 0; l < strlen; l++) {
      if (counts[W[l] - 'a'] < K) {
        continue;
      }

      int sublen = 0;
      for (int r = l; r < strlen; r++) {
        if (W[l] == W[r]) {
          sublen += 1;
        }

        if (sublen == K) {
          minlen = min(minlen, r - l + 1);
          maxlen = max(maxlen, r - l + 1);
          break;
        }
      }
    }

    if (minlen == 10001 || maxlen == 0) {
      cout << -1 << "\n";
    } else {
    cout << minlen << " " << maxlen << "\n";
    }
  }

  return 0;
}