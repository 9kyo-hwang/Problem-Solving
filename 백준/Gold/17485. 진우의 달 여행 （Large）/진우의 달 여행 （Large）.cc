#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 100001;
constexpr int OFFSET[] = {-1, 0, 1,};

int N, M;
vector<vector<int>> m;
vector<vector<vector<int>>> L;

int mat(int i, int j, int pd) {
  if (L[pd][i][j] != MAX) return L[pd][i][j];

  if (i == 0) { // 시작선
    L[pd][i][j] = m[i][j];
  } else {
    for (const int dir : {0, 1, 2}) {
      if (dir == pd) continue;

      int nj = j + OFFSET[dir];
      if (nj < 0 || nj >= M) continue;

      L[pd][i][j] = min(L[pd][i][j], mat(i - 1, nj, dir) + m[i][j]);
    }
  }

  return L[pd][i][j];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;

  m = vector<vector<int>>(N, vector<int>(M));
  for (auto &r : m) {
    for (auto &c : r) {
      cin >> c;
    }
  }
  L = vector<vector<vector<int>>>(3, vector<vector<int>>(N, vector<int>(M, MAX)));

  int answer = MAX;
  for (int j = 0; j < M; j++) {
    for(const int dir : {0, 1, 2}) {
      answer = min(answer, mat(N - 1, j, dir));
    }
  }

  cout << answer;
  return 0;
}