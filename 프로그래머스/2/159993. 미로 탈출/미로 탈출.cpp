#include <string>
#include <vector>
#include <queue>

#define Chr static_cast<char>

using namespace std;

enum class EMaze
{
    START = 'S',
    EXIT = 'E',
    LEVER = 'L',
    PATHWAY = 'O',
    WALL = 'X',
};

const vector<pair<int, int>> Offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool OutOfBound(const vector<string>& Maps, int X, int Y)
{
    return X < 0 || X >= Maps.size() || Y < 0 || Y >= Maps[0].size();
}

int BFS(const vector<string>& Maps, const pair<int, int>& Start, const pair<int, int>& Exit, vector<vector<int>> Distances)
{
    deque<pair<int, int>> Q;
    Q.push_back(Start);
    Distances[Start.first][Start.second] = 0;
    
    while(!Q.empty())
    {
        const auto [X, Y] = Q.front();
        Q.pop_front();
        
        if(Exit == make_pair(X, Y))
        {
            return Distances[X][Y];
        }
        
        for(const auto& [Dx, Dy] : Offset)
        {
            int Nx = X + Dx, Ny = Y + Dy;
            if(OutOfBound(Maps, Nx, Ny) || Distances[Nx][Ny] != -1)
            {
                continue;
            }
            
            Distances[Nx][Ny] = Distances[X][Y] + 1;
            Q.emplace_back(Nx, Ny);
        }
    }
    
    return -1;
}

int solution(vector<string> InMaps)
{
    vector Distances(InMaps.size(), vector(InMaps[0].size(), -1));
    pair<int, int> StartPos, ExitPos, LeverPos;
    
    for(int i = 0; i < InMaps.size(); ++i)
    {
        for(int j = 0; j < InMaps[i].size(); ++j)
        {
            if(InMaps[i][j] == Chr(EMaze::START))
            {
                StartPos = {i, j};
            }
            else if(InMaps[i][j] == Chr(EMaze::EXIT))
            {
                ExitPos = {i, j};
            }
            else if(InMaps[i][j] == Chr(EMaze::LEVER))
            {
                LeverPos = {i, j};
            }
            else if(InMaps[i][j] == Chr(EMaze::WALL))
            {
                Distances[i][j] = 0;
            }
        }
    }
    
    int StartToLever = BFS(InMaps, StartPos, LeverPos, Distances);
    if(StartToLever == -1)
    {
        return -1;
    }
    
    int LeverToExit = BFS(InMaps, LeverPos, ExitPos, Distances);
    if(LeverToExit == -1)
    {
        return -1;
    }
    
    return StartToLever + LeverToExit;
}