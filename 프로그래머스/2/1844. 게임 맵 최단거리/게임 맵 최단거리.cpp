#include<vector>
#include<queue>
#include<tuple>

using namespace std;
using pii = pair<int, int>;

const vector<pii> offset = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

int solution(vector<vector<int>> maps) {
    const int n = maps.size(), m = maps[0].size();
    
    queue<pii> q;
    q.emplace(0, 0);

    while(!q.empty()) {
        const auto [x, y] = q.front();
        q.pop();
        
        for(const auto &[dx, dy] : offset) {
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || maps[nx][ny] != 1) {
                continue;
            }
            
            maps[nx][ny] = maps[x][y] + 1;
            q.emplace(nx, ny);
        }
    }

    return maps[n - 1][m - 1] == 1 ? -1 : maps[n - 1][m - 1];
}