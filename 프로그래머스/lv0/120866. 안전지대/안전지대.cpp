#include <string>
#include <vector>

using namespace std;

constexpr int OFFSET[][2] = {
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
};

int solution(vector<vector<int>> board) {
    int answer = board.size() * board.size();
    for(int x = 0; x < board.size(); x++) {
        for(int y = 0; y < board[0].size(); y++) {
            if(board[x][y] != 1)
                continue;
            
            answer -= 1;
            for(const auto &dir : OFFSET) {
                int nx = x + dir[0], ny = y + dir[1];
                if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size() || board[nx][ny] != 0)
                    continue;
                
                board[nx][ny] = 2;
                answer -= 1;
            }
        }
    }
    return answer;
}