#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    int M, N; cin >> M >> N;
    vector<string> Map(N);
    for(string& Row : Map)
    {
        cin >> Row;
    }
    
    deque<tuple<int, int, int>> Q;
    vector<vector<bool>> Visited(N, vector(M, false));
    const vector<pair<int, int>> Offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    auto IsOutOfBound = [&](int x, int y)
    {
        return x < 0 || x >= N || y < 0 || y >= M;
    };
    
    Q.emplace_back(0, 0, 0);
    Visited[0][0] = true;
    
    while(!Q.empty())
    {
        const auto [x, y, Break] = Q.front();
        Q.pop_front();
        
        if(x == N - 1 && y == M - 1)
        {
            cout << Break;
            break;
        }
        
        for(const auto& [dx, dy] : Offset)
        {
            int nx = x + dx, ny = y + dy;
            if(IsOutOfBound(nx, ny) || Visited[nx][ny])
            {
                continue;
            }
            
            Visited[nx][ny] = true;
            if(Map[nx][ny] == '0')
            {
                Q.emplace_front(nx, ny, Break);
            }
            else if(Map[nx][ny] == '1')
            {
                Q.emplace_back(nx, ny, Break + 1);
            }
        }
    }
    
    return 0;
}