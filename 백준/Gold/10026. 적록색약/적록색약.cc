#include <iostream>
#include <vector>

using namespace std;

int N;

void dfs(vector<vector<char>> &grid, int x, int y, char color) {
  if (x < 0 || x >= N || y < 0 || y >= N) {
    return;
  }

  if (grid[x][y] != color) {
    return;
  }

  grid[x][y] = 'A';

  dfs(grid, x - 1, y, color);
  dfs(grid, x, y + 1, color);
  dfs(grid, x + 1, y, color);
  dfs(grid, x, y - 1, color);
 }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  vector<vector<char>> grid1, grid2;
  grid1.resize(N, vector<char>(N));
  grid2.resize(N, vector<char>(N));

  char ch;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> ch;
      grid1[i][j] = ch;
      
      if (ch == 'R') {
        ch = 'G';
      }
      grid2[i][j] = ch;
    }
  }

  int count1 = 0, count2 = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid1[i][j] == 'A') {
        continue;
      }

      dfs(grid1, i, j, grid1[i][j]);
      count1 += 1;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid2[i][j] == 'A') {
        continue;
      }

      dfs(grid2, i, j, grid2[i][j]);
      count2 += 1;
    }
  }

  cout << count1 << " " << count2;

  return 0;
}