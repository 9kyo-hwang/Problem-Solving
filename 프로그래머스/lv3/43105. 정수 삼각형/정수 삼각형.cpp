#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int size = triangle.size();
	vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
    dp[1][1] = triangle[0][0];
    
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i - 1][j - 1];
		}
	}
	
	int answer = 0;
	for (int j = 1; j <= size; j++)
		answer = max(answer, dp[size][j]);
	return answer;
}