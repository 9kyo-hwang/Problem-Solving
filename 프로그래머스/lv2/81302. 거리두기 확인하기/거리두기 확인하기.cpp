#include <string>
#include <vector>
#include <queue>

using namespace std;

constexpr int OFFSET[3][4][2] = 
{
    {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    },
    {
        {-2, 0},
        {0, 2},
        {2, 0},
        {0, -2},        
    },
    {
        {-1, 1},
        {1, 1},
        {1, -1},
        {-1, -1},   
    },
};

vector<pair<int, int>> positions;
bool is_follow(const vector<string> &place)
{
    for(const auto &[x, y] : positions)
    {
        for(int offset : {0, 1, 2})
        {
            for(int dir : {0, 1, 2, 3})
            {
                int nx = x + OFFSET[offset][dir][0], ny = y + OFFSET[offset][dir][1];
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || place[nx][ny] != 'P')
                    continue;
                
                if(offset == 0) return false;
                
                if(offset == 1)
                {
                    switch(dir)
                    {
                        case 0: if(place[x - 1][y] != 'X') return false; break;
                        case 1: if(place[x][y + 1] != 'X') return false; break;
                        case 2: if(place[x + 1][y] != 'X') return false; break;
                        case 3: if(place[x][y - 1] != 'X') return false; break;
                        default: break;
                    }
                }
                
                if(offset == 2)
                {
                    switch(dir)
                    {
                        case 0: if(place[x - 1][y] == 'O' || place[x][y + 1] == 'O') return false; break;
                        case 1: if(place[x + 1][y] == 'O' || place[x][y + 1] == 'O') return false; break;
                        case 2: if(place[x + 1][y] == 'O' || place[x][y - 1] == 'O') return false; break;
                        case 3: if(place[x - 1][y] == 'O' || place[x][y - 1] == 'O') return false; break;
                        default: break;
                    }
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer;
    for(const auto &place : places)
    {
        positions.clear();
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(place[i][j] == 'P')
                    positions.emplace_back(i, j);
            }
        }
        
        answer.emplace_back(is_follow(place));
    }
    return answer;
}