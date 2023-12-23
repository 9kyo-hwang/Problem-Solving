#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> SP1, SP2;

bool is_correct_vaccine() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (SP1[i][j] != SP2[i][j]) {
        return false;
      }
    }
  }

  return true;
}

void flood_fill(const int from, const int to, int x, int y) {
  if (x < 0 || x >= N || y < 0 || y >= M || SP1[x][y] != from) {
    return;
  }

  SP1[x][y] = to;
  flood_fill(from, to, x - 1, y);
  flood_fill(from, to, x, y + 1);
  flood_fill(from, to, x + 1, y);
  flood_fill(from, to, x, y - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  SP1.assign(N, vector(M, 0));
  SP2.assign(N, vector(M, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> SP1[i][j];
    }
  }

  int x, y, from, to;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> SP2[i][j];

      if (SP1[i][j] != SP2[i][j]) {
        x = i;
        y = j;
        
        from = SP1[i][j];
        to = SP2[i][j];
      }
    }
  }

  flood_fill(from, to, x, y);
  if (is_correct_vaccine()) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}