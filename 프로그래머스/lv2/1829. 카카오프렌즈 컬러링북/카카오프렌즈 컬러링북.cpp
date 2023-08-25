#include <vector>

using namespace std;

vector<vector<bool>> visited;
int count_cells(vector<vector<int>> &p, const int m, const int n, const int c, int x, int y) {
    if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) {
        return 0;
    } else if(p[x][y] == 0 || p[x][y] != c) {
        return 0;
    } else {
        visited[x][y] = true;
        return 1 + count_cells(p, m, n, c, x - 1, y) + count_cells(p, m, n, c, x, y + 1) + count_cells(p, m, n, c, x + 1, y) + count_cells(p, m, n, c, x, y - 1);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    visited = vector(m, vector(n, false));
    int cnt = 0;
    int max_cells = 0;
    for(int x = 0; x < m; x++) {
        for(int y = 0; y < n; y++) {
            int c = picture[x][y];
            int result = count_cells(picture, m, n, c, x, y);
            if(result == 0)
                continue;
            
            cnt += 1;
            if(result > max_cells) {
                max_cells = result;
            }
        }
    }
    
    return {cnt, max_cells};
}