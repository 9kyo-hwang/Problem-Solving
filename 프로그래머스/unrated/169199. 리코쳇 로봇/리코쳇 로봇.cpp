#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

constexpr int OFFSET[][2] = 
{
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

int solution(vector<string> board) 
{
    int N = board.size(), M = board[0].size();
    vector visited(N, vector(M, false));
    
    pair<int, int> begin, end;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == 'R') begin = {i, j};
            else if(board[i][j] == 'G') end = {i, j};
        }
    }
    
    queue<tuple<int, int, int>> q;
    q.emplace(begin.first, begin.second, 0);
    visited[begin.first][begin.second] = true;
    
    int answer = -1;
    while(!q.empty())
    {
        const auto [x, y, step] = q.front(); q.pop();
        if(x == end.first && y == end.second)
        {
            answer = step;
            break;
        }
        
        for(auto &dir : OFFSET)
        {
            int nx = x, ny = y;
            while(nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 'D')
            {
                nx += dir[0];
                ny += dir[1];
            }
            
            nx -= dir[0];
            ny -= dir[1];
            
            if((nx == x && ny == y) || visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            q.emplace(nx, ny, step + 1);
        }
    }
    
    return answer;
}