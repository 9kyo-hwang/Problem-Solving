#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int X;
  cin >> X;

  queue<int> q;
  q.emplace(X);

  unordered_map<int, int> map;
  map[X] = 0;

  while(!q.empty()) {
    int x = q.front();
    q.pop();

    if(x == 1) {
      break;
    }

    if(x % 3 == 0 && map[x / 3] == 0) {
      map[x / 3] = map[x] + 1;
      q.emplace(x / 3);
    }

    if(x % 2 == 0 && map[x / 2] == 0) {
      map[x / 2] = map[x] + 1;
      q.emplace(x / 2);
    }

    if(map[x - 1] == 0) {
      map[x - 1] = map[x] + 1;
      q.emplace(x - 1);
    }
  }

  cout << map[1];
  return 0;
}