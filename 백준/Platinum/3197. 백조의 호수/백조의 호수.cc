#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <numeric>

#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

const vector<pii> offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int R, C;
vector<string> lake;
vector<vector<bool>> is_water_space;
vector<pii> swan_pos;
deque<pii> waterq;
vector<int> parents;

int convert_to_1d(pii p) { return p.X * C + p.Y; }
int convert_to_1d(int x, int y) { return x * C + y; }

int find(int x) {
  while (x != parents[x]) {
    parents[x] = parents[parents[x]];
    x = parents[x];
  }
  return parents[x];
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);

  if (x < y) {
    parents[y] = x;
  } else if (x > y) {
    parents[x] = y;
  }
}

bool is_out_of_bound(int x, int y) {
  return x < 0 || x >= R || y < 0 || y >= C;
}

void unite_water_space() {
  for (const auto [x, y] : waterq) {
    for (const auto &[dx, dy] : offset) {
      int nx = x + dx, ny = y + dy;
      if (is_out_of_bound(nx, ny) || !is_water_space[nx][ny]) {
        continue;
      }

      unite(convert_to_1d(x, y), convert_to_1d(nx, ny));
    }
  }
}

bool did_swans_meet() { 
  return find(convert_to_1d(swan_pos[0])) == find(convert_to_1d(swan_pos[1]));
}

void melt_glaciers() {
  for (int repeat = waterq.size(); repeat > 0; --repeat) {
    const auto [x, y] = waterq.front();
    waterq.pop_front();

    for (const auto &[dx, dy] : offset) {
      int nx = x + dx, ny = y + dy;
      if (is_out_of_bound(nx, ny) || is_water_space[nx][ny]) {
        continue;
      }
      is_water_space[nx][ny] = true;
      waterq.emplace_back(nx, ny);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;

  lake.resize(R);
  for (auto &str : lake) {
    cin >> str;
  }

  is_water_space.assign(R, vector(C, false));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (lake[i][j] == 'X') {
        continue;
      }

      waterq.emplace_back(i, j);
      is_water_space[i][j] = true;

      if (lake[i][j] == 'L') {
        swan_pos.emplace_back(i, j);
      }
    }
  }

  parents.resize(R * C);
  iota(parents.begin(), parents.end(), 0);

  int days = 0;
  while (!waterq.empty()) {
    unite_water_space();
    if (did_swans_meet()) {
      break;
    }
    melt_glaciers();
    days += 1;
  }

  cout << days;
  
  return 0;
}