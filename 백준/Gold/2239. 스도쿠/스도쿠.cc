#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

vector<vector<int>> sudoku;
vector<pii> empty_pos;

bool promising(int x, int y) {
  for (int j = 0; j < 9; ++j) {
    if (y == j) {
      continue;
    }

    if (sudoku[x][y] == sudoku[x][j]) {
      return false;
    }
  }

  for (int i = 0; i < 9; ++i) {
    if (x == i) {
      continue;
    }

    if (sudoku[x][y] == sudoku[i][y]) {
      return false;
    }
  }

  int sec_x = (x / 3) * 3, sec_y = (y / 3) * 3;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (sec_x + i == x && sec_y + j == y) {
        continue;
      }

      if (sudoku[x][y] == sudoku[sec_x + i][sec_y + j]) {
        return false;
      }
    }
  }

  return true;
}

bool backtracking(int idx = 0) {
  if (idx == empty_pos.size()) {
    for (const auto &r : sudoku) {
      for (const auto &c : r) {
        cout << c;
      }
      cout << "\n";
    }
    return true;
  }

  const auto &[x, y] = empty_pos[idx];
  for (int i = 1; i <= 9; ++i) {
    sudoku[x][y] = i;

    if (!promising(x, y)) {
      sudoku[x][y] = 0;
      continue;
    }

    if (backtracking(idx + 1)) {
      return true;
    }

    sudoku[x][y] = 0;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  sudoku.assign(9, vector(9, 0));
  for (int i = 0; i < 9; ++i) {
    string s;
    cin >> s;

    for (int j = 0; j < 9; ++j) {
      sudoku[i][j] = s[j] - '0';

      if (sudoku[i][j] == 0) {
        empty_pos.emplace_back(i, j);
      }
    }
  }

  backtracking();

  return 0;
}