#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    int N, M; scanf(" %d %d", &N, &M);
    vector Map(N, vector(M, 0));
    for(auto& r : Map)
    {
        for(auto& c : r)
        {
            scanf("%1d", &c);
        }
    }
    
    vector Visited(N, vector(M, vector(2, -1)));
    vector<pair<int, int>> Offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    auto OutOfBound = [&](int X, int Y)
    {
        return X < 0 || X >= N || Y < 0 || Y >= M;
    };
    
    deque<tuple<int, int, bool>> Q;
    
    Q.emplace_back(0, 0, false);
    Visited[0][0][0] = 1;
    
    while(!Q.empty())
    {
        const auto [X, Y, Flag] = Q.front();
        Q.pop_front();
        
        if(X == N - 1 && Y == M - 1)
        {
            break;
        }
        
        for(const auto& [Dx, Dy] : Offset)
        {
            int Nx = X + Dx, Ny = Y + Dy;
            if(OutOfBound(Nx, Ny) || Visited[Nx][Ny][Flag] != -1)
            {
                continue;
            }
            
            if(!Flag && Map[Nx][Ny] == 1)
            {
                Visited[Nx][Ny][1] = Visited[X][Y][0] + 1;
                Q.emplace_back(Nx, Ny, true);
            }
            else if(Map[Nx][Ny] == 0)
            {
                Visited[Nx][Ny][Flag] = Visited[X][Y][Flag] + 1;
                Q.emplace_back(Nx, Ny, Flag);
            }
        }
    }
    
    int Answer;
    if(Visited[N - 1][M - 1][0] != -1 && Visited[N - 1][M - 1][1] != -1)
    {
        Answer = min(Visited[N - 1][M - 1][0], Visited[N - 1][M - 1][1]);
    }
    else
    {
        Answer = max(Visited[N - 1][M - 1][0], Visited[N - 1][M - 1][1]);
    }
    printf("%d", Answer);

    return 0;
}