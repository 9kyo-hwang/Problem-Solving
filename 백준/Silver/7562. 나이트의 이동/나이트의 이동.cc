#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    const vector<pair<int, int>> Offset{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    
    int T; cin >> T;
    while(T--)
    {
        int L; cin >> L;
        vector<vector<int>> Chess(L, vector(L, 0));
        
        int BeginX, BeginY; cin >> BeginX >> BeginY;
        int EndX, EndY; cin >> EndX >> EndY;
        
        deque<pair<int, int>> Q;
        Q.emplace_back(BeginX, BeginY);
        
        auto OutOfBound = [&](int x, int y)
        {
            return x < 0 || x >= L || y < 0 || y >= L;
        };
        
        while(!Q.empty())
        {
            const auto [x, y] = Q.front();
            Q.pop_front();
            
            if(x == EndX && y == EndY)
            {
                cout << Chess[x][y] << "\n";
                break;
            }
            
            for(const auto& [dx, dy] : Offset)
            {
                int nx = x + dx, ny = y + dy;
                if(OutOfBound(nx, ny) || Chess[nx][ny] > 0)
                {
                    continue;
                }

                Chess[nx][ny] = Chess[x][y] + 1;
                Q.emplace_back(nx, ny);
            }
        }
    }
    
    return 0;
}