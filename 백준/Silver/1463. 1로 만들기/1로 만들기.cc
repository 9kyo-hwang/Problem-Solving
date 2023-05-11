#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector visited(n, 0);
  queue<pair<int, int>> q;
  q.emplace(n, 0);

  while (!q.empty()) {
    auto [num, step] = q.front();
    q.pop();

    if (num == 1) {
      cout << step;
      break;
    }

    if (num % 3 == 0 && visited[num / 3] == 0) {
      visited[num / 3] = 1;
      q.emplace(num / 3, step + 1);
    }

    if (num % 2 == 0 && visited[num / 2] == 0) {
      visited[num / 2] = 1;
      q.emplace(num / 2, step + 1);
    }

    if (visited[num - 1] == 0) {
      visited[num - 1] = 1;
      q.emplace(num - 1, step + 1);
    }
  }
  return 0;
}