#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int M, N;
  cin >> M >> N;

  vector is_a_ripe_tomato(N, vector(M, false));
  deque<pii> q;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int state;
      cin >> state;

      switch (state) {
        case 1:
          q.emplace_back(i, j);
        case -1:
          is_a_ripe_tomato[i][j] = true;
          break;
        default:
          break;
      }
    }
  }

  vector<pii> offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int days = -1;

  auto is_out_of_bound = [&](int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
  };

  while (!q.empty()) {
    for (int repeat = q.size(); repeat > 0; --repeat) {
      const auto [x, y] = q.front();
      q.pop_front();

      for (const auto &[dx, dy] : offset) {
        int nx = x + dx, ny = y + dy;
        if (is_out_of_bound(nx, ny) || is_a_ripe_tomato[nx][ny]) {
          continue;
        }

        is_a_ripe_tomato[nx][ny] = true;
        q.emplace_back(nx, ny);
      }
    }
    days += 1;
  }

  auto are_all_tomatoes_ripe = [&]() {
    for (const auto &r : is_a_ripe_tomato) {
      for (const auto &c : r) {
        if (c == false) {
          return false;
        }
      }
    }
    return true;
  };

  if (!are_all_tomatoes_ripe()) {
    days = -1;
  }

  cout << days;

  return 0;
}