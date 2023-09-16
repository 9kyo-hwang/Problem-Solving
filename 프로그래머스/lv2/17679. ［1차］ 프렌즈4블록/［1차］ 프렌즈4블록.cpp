#include <string>
#include <vector>
#include <cctype>
#include <set>
#include <algorithm>

using namespace std;

const int OFFSET[][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
set<pair<int, int>> s;

bool is_adjacency(const vector<string> &v, int x, int y)
{
    if(v[x][y] == '.') return false;
    
    char c = v[x][y];
    for(auto &dir : OFFSET)
    {
        if(v[x + dir[0]][y + dir[1]] != c)
            return false;
    }
    return true;
}

void get(int m, int n, const vector<string> &v)
{
    for(int i = 0; i < m - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(!is_adjacency(v, i, j)) continue;
            
            for(auto &dir : OFFSET)
            {
                s.emplace(i + dir[0], j + dir[1]);
            }
        }
    }
}

void remove(int m, int n, vector<string> &v)
{
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
        {
            if(v[i][j] == '.') continue;

            int ni = i + 1;
            while(ni < m && v[ni][j] == '.') ni++;
            ni--;

            if(ni != i)
            {
                v[ni][j] = v[i][j];
                v[i][j] = '.';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) 
{
    int cnt = 0;
    while(true)
    {
        s.clear(); 
        
        get(m, n, board);
        
        if(s.empty()) break;
        
        cnt += s.size();
        
        for(const auto &[x, y] : s) 
            board[x][y] = '.';
        
        remove(m, n, board);
    }
    
    return cnt;
}