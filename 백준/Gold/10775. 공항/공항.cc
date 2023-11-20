#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> map;

int find(int x) {
  if (map.find(x) == map.end()) {
    return x;
  }

  return map[x] = find(map[x]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int G;
  cin >> G;

  int P;
  cin >> P;

  int i;
  for (i = 0; i < P; i++) {
    int gi;
    cin >> gi;

    int p = find(gi);
    if (p == 0) {
      break;
    }

    map[p] = p - 1;
  }

  cout << i;
  return 0;
}