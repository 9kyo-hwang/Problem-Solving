#include <string>
#include <vector>

using namespace std;

size_t n, m;
vector<bool> check;

int dfs(vector<vector<int>> &land, int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || land[x][y] != 1) {
        return 0;
    }
    
    land[x][y] = 2;
    check[y] = true;
    return 1 + dfs(land, x - 1, y) + dfs(land, x, y + 1) + dfs(land, x + 1, y) + dfs(land, x, y - 1);
}

int solution(vector<vector<int>> land) {
    n = land.size(), m = land[0].size();
    check.assign(m, false);
    vector<int> ans(m, 0);
    
    for(int j = 0; j < m; ++j) {
        for(int i = 0; i < n; ++i) {
            if(land[i][j] != 1) {
                continue;
            }
            
            int cnt = dfs(land, i, j);
            for(int k = 0; k < m; ++k) {
                if(check[k]) {
                    ans[k] += cnt;
                    check[k] = false;
                }
            }
        }
    }
    
    int answer = 0;
    for(int j = 0; j < m; ++j) {
        if(ans[j] > answer) {
            answer = ans[j];
        }
    }
    return answer;
}