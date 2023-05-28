#include <iostream>
#include <array>
#include <vector>

#define EMPTY 0

using namespace std;

vector<pair<int, int>> v;
array<array<int, 9>, 9> arr;

bool Promising(size_t count) {
  const auto &[empty_x, empty_y] = v[count];

  for (int col = 0; col < 9; col++) { // 행에 겹치는 숫자 있는 지 확인
    if ((col != empty_y) && (arr[empty_x][col] == arr[empty_x][empty_y]))
      return false;
  }

  for (int row = 0; row < 9; row++) { // 열에 겹치는 숫자 있는 지 확인
    if ((row != empty_x) && (arr[row][empty_y] == arr[empty_x][empty_y]))
      return false;
  }

  // 구역에 겹치는 숫자 있는 지 확인
  int area_x = empty_x / 3;
  int area_y = empty_y / 3;
  for (int row = area_x * 3; row < area_x * 3 + 3; row++) {
    for (int col = area_y * 3; col < area_y * 3 + 3; col++) {
      if ((row != empty_x) && (col != empty_y) && (arr[empty_x][empty_y] == arr[row][col]))
        return false;
    }
  }

  return true;
}

bool Sudoku(size_t count = 0) {
  if (count == v.size())
    return true;

  const auto &[x, y] = v[count];
  for (int i = 1; i <= 9; i++) {
    arr[x][y] = i;
    if (!Promising(count))
      continue;

    if (Sudoku(count + 1))
      return true;
  }
  arr[x][y] = 0;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == EMPTY)
        v.emplace_back(i, j);
    }
  }

  if (Sudoku()) {
    for(const auto &i : arr) {
      for(const auto &j : i) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}