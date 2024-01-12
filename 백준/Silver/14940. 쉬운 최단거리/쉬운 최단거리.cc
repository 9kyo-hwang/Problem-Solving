#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  pii target_pos;
  vector map(n, vector(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> map[i][j];
      if (map[i][j] == 2) {
        target_pos = {i, j};
      }
    }
  }

  vector dist(n, vector(m, 0));
  vector visited(n, vector(m, false));

  deque<pii> dq;
  dq.emplace_back(target_pos);
  visited[target_pos.X][target_pos.Y] = true;

  const vector<pii> offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  while (!dq.empty()) {
    const auto [x, y] = dq.front();
    dq.pop_front();

    for (const auto &[dx, dy] : offset) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 0 ||
          visited[nx][ny]) {
        continue;
      }

      dist[nx][ny] = dist[x][y] + 1;
      visited[nx][ny] = true;
      dq.emplace_back(nx, ny);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] == 1 && !visited[i][j]) {
        dist[i][j] = -1;
      }
    }
  }

  for (const auto &r : dist) {
    for (const auto &c : r) {
      cout << c << " ";
    }
    cout << "\n";
  }

  return 0;
}