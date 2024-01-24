#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

size_t n, m;
unordered_set<int> cols;

int dfs(vector<vector<int>> &land, int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || land[x][y] != 1) {
        return 0;
    }
    
    land[x][y] = 2;
    cols.emplace(y);
    return 1 + dfs(land, x - 1, y) + dfs(land, x, y + 1) + dfs(land, x + 1, y) + dfs(land, x, y - 1);
}

int solution(vector<vector<int>> land) {
    n = land.size(), m = land[0].size();
    vector<int> areas(m, 0);
    
    for(int j = 0; j < m; ++j) {
        for(int i = 0; i < n; ++i) {
            if(land[i][j] != 1) {
                continue;
            }
            
            cols.clear();
            int cnt = dfs(land, i, j);
            for(const int col : cols) {
                areas[col] += cnt;
            }
        }
    }
    
    int answer = 0;
    for(int j = 0; j < m; ++j) {
        if(areas[j] > answer) {
            answer = areas[j];
        }
    }
    return answer;
}