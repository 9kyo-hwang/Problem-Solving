#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int HORSE[][2] = {
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1}
};

constexpr int MONKEY[][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

enum class EMap : int {
  EMPTY,
  WALL,
};

int K, W, H; // width, height
vector<vector<int>> map;

struct Monkey {
  int pos_x, pos_y, horse_move_cnt, total_move_cnt;

  Monkey(int x, int y, int h_cnt, int t_cnt) : pos_x(x), pos_y(y), horse_move_cnt(h_cnt), total_move_cnt(t_cnt) {}
};

bool CheckFtn(int x, int y) {
  return x < 0 || x >= H || y < 0 || y >= W || map[x][y] == static_cast<int>(EMap::WALL);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> K;
  cin >> W >> H;

  map = vector<vector<int>>(H, vector<int>(W));
  for (auto &r : map) {
    for (auto &c : r) {
      cin >> c;
    }
  }

  vector<vector<vector<bool>>> visited(31, vector<vector<bool>>(H, vector<bool>(W, false)));

  queue<Monkey> q;
  q.emplace(0, 0, 0, 0);
  visited[0][0][0] = true;

  int answer = -1;
  while (!q.empty()) {
    const auto &[x, y, h_cnt, t_cnt] = q.front();
    q.pop();

    if (x == H - 1 && y == W - 1) {
      answer = t_cnt;
      break;
    }

    if(h_cnt < K) {
      for (auto &dir : HORSE) {
        int nx = x + dir[0], ny = y + dir[1];
        if (CheckFtn(nx, ny) || visited[h_cnt + 1][nx][ny])
          continue;

        visited[h_cnt + 1][nx][ny] = true;
        q.emplace(nx, ny, h_cnt + 1, t_cnt + 1);
      }
    }
      
    for (auto &dir : MONKEY) {
      int nx = x + dir[0], ny = y + dir[1];
      if (CheckFtn(nx, ny) || visited[h_cnt][nx][ny])
        continue;

      visited[h_cnt][nx][ny] = true;
      q.emplace(nx, ny, h_cnt, t_cnt + 1);
    }
  }

  cout << answer;

  return 0;
}