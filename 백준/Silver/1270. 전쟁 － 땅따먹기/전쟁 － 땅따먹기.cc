#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  unordered_map<long, int> map;

  while (n--) {
    map.clear();
      
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
      long N;
      cin >> N;

      map[N] += 1;
    }

    auto max_elem = max_element(map.begin(), map.end(),
                                [](const auto& lhs, const auto& rhs) {
                                  return lhs.second < rhs.second;
                                });

    if (max_elem->second > T / 2) {
      cout << max_elem->first << "\n";
    } else {
      cout << "SYJKGW\n";
    }
  }

  return 0;
}