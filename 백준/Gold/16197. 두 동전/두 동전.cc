#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;

bool isOut(int x, int y) { return x < 0 || x >= N || y < 0 || y >= M; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;

  vector<vector<int>> board(N, vector<int>(M, 0));
  queue<tuple<pair<int, int>, pair<int, int>, int>> q;

  pair<int, int> pos1, pos2;
  char ch;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> ch;
      if (ch == 'o') {  // coin
        board[i][j] = 0;
        if (cnt == 0) {
          cnt += 1;
          pos1 = {i, j};
        } else if (cnt == 1) {
          cnt += 1;
          pos2 = {i, j};
        }
      } else if (ch == '.') {  // empty
        board[i][j] = 0;
      } else if (ch == '#') {  // wall
        board[i][j] = 1;
      }
    }
  }

  q.push({pos1, pos2, 0});

  const int OFFSET[][2] = {
      {-1, 0},
      {0, 1},
      {1, 0},
      {0, -1},
  };

  int answer = -1;
  while (!q.empty()) {
    const auto [pos1, pos2, step] = q.front();
    const auto &[x1, y1] = pos1;
    const auto &[x2, y2] = pos2;
    q.pop();

    if (step > 10) {
      break;
    }

    bool b1 = isOut(x1, y1), b2 = isOut(x2, y2);
    if (b1 != b2) {
      answer = step;
      break;
    }

    if (b1 && b2) {
      continue;
    }

    for (const auto &dir : OFFSET) {
      int nx1 = x1 + dir[0], ny1 = y1 + dir[1];
      int nx2 = x2 + dir[0], ny2 = y2 + dir[1];

      pair<int, int> npos1, npos2;
      if (!isOut(nx1, ny1) && board[nx1][ny1] == 1) {
        npos1 = {x1, y1};
      } else {
        npos1 = {nx1, ny1};
      }

      if (!isOut(nx2, ny2) && board[nx2][ny2] == 1) {
        npos2 = {x2, y2};
      } else {
        npos2 = {nx2, ny2};
      }

      q.push({npos1, npos2, step + 1});
    }
  }

  cout << answer;

  return 0;
}