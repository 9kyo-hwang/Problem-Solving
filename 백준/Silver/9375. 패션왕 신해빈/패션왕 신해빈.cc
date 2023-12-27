#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    unordered_map<string, int> map;
    while (n--) {
      string name, type;
      cin >> name >> type;

      map[type] += 1;
    }

    int cases = 1;
    for (const auto &[key, value] : map) {
      cases *= (value + 1);
    }

    cout << cases - 1 << "\n";
  }

  return 0;
}