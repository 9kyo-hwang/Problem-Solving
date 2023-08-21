#include <string>
#include <vector>

using namespace std;

constexpr int MAX = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // [i, j] 좌표에 도달할 수 있는 경우의 수
    
    for(const auto p : puddles) // 갈 수 없는 위치
        dp[p[1]][p[0]] = MAX;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp[i][j] == MAX) { // 갈 수 없는 위치는 이 좌표에 도달할 수 있는 경우의 수를 0으로 설정
                dp[i][j] = 0;
            } else if(i == 1 && j == 1) { // 시작점
                dp[i][j] = 1;
            } else if(i == 1) { // 1행은 왼쪽에서만 올 수 있음
                dp[i][j] = dp[i][j - 1];
            } else if(j == 1) { // 1열은 위쪽에서만 올 수 있음
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MAX;
            }
        }
    }
    
    return dp[n][m];
}