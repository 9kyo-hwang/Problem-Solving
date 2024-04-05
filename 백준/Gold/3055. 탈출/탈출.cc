#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    using FPos = pair<int, int>;
    enum class FForest
    {
        EMPTY = '.',
        WATER = '*',
        STONE = 'X',
        CAVE = 'D',
        HEDGEHOG = 'S',
    };
    auto Empty = [&]() { return static_cast<char>(FForest::EMPTY); };
    auto Water = [&]() { return static_cast<char>(FForest::WATER); };
    auto Stone = [&]() { return static_cast<char>(FForest::STONE); };
    auto Cave = [&]() { return static_cast<char>(FForest::CAVE); };
    auto Hedgehog = [&]() { return static_cast<char>(FForest::HEDGEHOG); };
    
    int R, C; cin >> R >> C;
    vector<string> Forest(R);
    deque<FPos> HedgehogQ, WaterQ;
    FPos CavePos;
    vector<vector<bool>> HedgehogVisited(R, vector(C, false));
    
    for(int i = 0; i < R; ++i)
    {
        cin >> Forest[i];
        for(int j = 0; j < C; ++j)
        {
            if(Forest[i][j] == Hedgehog())
            {
                HedgehogQ.emplace_back(i, j);
                HedgehogVisited[i][j] = true;
                Forest[i][j] = Empty();
            }
            else if(Forest[i][j] == Water())
            {
                WaterQ.emplace_back(i, j);
            }
            else if(Forest[i][j] == Cave())
            {
                CavePos = {i, j};
            }
        }
    }
    
    
    const vector<FPos> Offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    auto OutOfBound = [&](int X, int Y) { return X < 0 || X >= R || Y < 0 || Y >= C; };
    
    auto IsArrived = [&]()
    {
        for(int Repeat = HedgehogQ.size(); Repeat > 0; --Repeat)
        {
            const auto [X, Y] = HedgehogQ.front();
            HedgehogQ.pop_front();
            
            if(X == CavePos.first && Y == CavePos.second)
            {
                return true;
            }
            else if(Forest[X][Y] == Water())
            {
                continue;
            }
            
            for(const auto& [Dx, Dy] : Offset)
            {
                int Nx = X + Dx, Ny = Y + Dy;
                if(OutOfBound(Nx, Ny) 
                || Forest[Nx][Ny] == Water() 
                || Forest[Nx][Ny] == Stone() 
                || HedgehogVisited[Nx][Ny]
                )
                {
                    continue;
                }
                
                HedgehogVisited[Nx][Ny] = true;
                HedgehogQ.emplace_back(Nx, Ny);
            }
        }
        
        return false;
    };
    
    auto WaterExpansion = [&]()
    {
        for(int Repeat = WaterQ.size(); Repeat > 0; --Repeat)
        {
            const auto [X, Y] = WaterQ.front();
            WaterQ.pop_front();
            
            for(const auto& [Dx, Dy] : Offset)
            {
                int Nx = X + Dx, Ny = Y + Dy;
                if(OutOfBound(Nx, Ny) || Forest[Nx][Ny] != Empty())
                {
                    continue;
                }
                
                Forest[Nx][Ny] = Water();
                WaterQ.emplace_back(Nx, Ny);
            }
        }
    };
    
    string Answer = "KAKTUS";
    for(int Tick = 0; Tick <= R * C; ++Tick)
    {
        if(IsArrived())
        {
            Answer = to_string(Tick);
            break;
        }
        WaterExpansion();
    }
    cout << Answer;
    
    return 0;
}