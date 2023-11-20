#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  constexpr int INF = 1e9;

  int N, M;
  cin >> N >> M;

  vector adjacent(N + 1, vector(N + 1, INF));
  for (int i = 1; i <= N; i++) adjacent[i][i] = 0;

  while (M--) {
    int A, B;
    cin >> A >> B;

    adjacent[A][B] = 1;
    adjacent[B][A] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        adjacent[i][j] = min(adjacent[i][j], adjacent[i][k] + adjacent[k][j]);
      }
    }
  }

  int min_cnt = INF, min_idx = 0;
  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    for (int j = 1; j <= N; j++) {
      cnt += adjacent[i][j];
    }

    if (cnt < min_cnt) {
      min_cnt = cnt;
      min_idx = i;
    }
  }

  cout << min_idx;

  return 0;
}