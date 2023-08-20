#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 100001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> costs(N, vector<int>(M));
  vector<vector<vector<int>>> dp(3, vector<vector<int>>(N, vector<int>(M, MAX))); // d 방향으로 [i, j] 칸을 진입함
  int answer = MAX;
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> costs[i][j];
      
      if(i == 0) {
        for(int d = 0; d < 3; d++) {
          dp[d][i][j] = costs[i][j];
        }
        continue;
      }

      if(j != 0) { // 왼쪽 벽이 아니라면 좌상단 진입 확인
        dp[0][i][j] = min(dp[1][i - 1][j - 1], dp[2][i - 1][j - 1]) + costs[i][j];
      }

      if(j != M - 1) { // 오른쪽 벽이 아니라면 우상단 진입 확인
        dp[2][i][j] = min(dp[0][i - 1][j + 1], dp[1][i - 1][j + 1]) + costs[i][j];
      }

      dp[1][i][j] = min(dp[0][i - 1][j], dp[2][i - 1][j]) + costs[i][j]; // 모든 위치에서 상단 진입 확인

      if(i == N - 1) {
        for(int d = 0; d <= 2; d++) {
          answer = min(answer, dp[d][i][j]);
        }
      }
    }
  }

  cout << answer;
  return 0;
}