#include <iostream>
#include <vector>

#define COMPARE(a, b) ((a < b) ? -1 : ((a > b) ? 1 : 0))

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int M, N;
  cin >> M >> N;

  vector<vector<int>> univ(M, vector<int>(N));

  for (auto &v : univ) {
    for (auto &i : v)
      cin >> i;
  }

  int count = 0;
  for (int crt = 0; crt < M - 1; crt++) { // 기준 우주
    for (int cmp = crt + 1; cmp < M; cmp++) { // 비교 우주
      bool is_same = true;

      for (int i = 0; i < N - 1; i++) { // 행성 크기 비교
        for (int j = i + 1; j < N; j++) {
          if (COMPARE(univ[crt][i], univ[crt][j]) != COMPARE(univ[cmp][i], univ[cmp][j])) {
            is_same = false;
            break;
          }
        }
        if (!is_same)
          break;
      }

      count += is_same;
    }
  }

  cout << count;

  return 0;
}