#include <cstdio>

int R, C;
char board[10000][500];

bool dfs(int x, int y) {
    if(x < 0 || x >= R || y < 0 || y >= C || board[x][y] == 'x') {
        return false;
    } else if(y == C - 1) {
        return true;
    } else {
        board[x][y] = 'x';
        return dfs(x - 1, y + 1) || dfs(x, y + 1) || dfs(x + 1, y + 1);
    }
}

int main() {
    scanf(" %d %d", &R, &C);
    for(int r = 0; r < R; ++r) {
        for(int c = 0; c < C; ++c) {
            scanf(" %c", &board[r][c]);
        }
    }
    
    int ans = 0;
    for(int r = 0; r < R; ++r) {
        ans += dfs(r, 0);
    }
    printf("%d", ans);
    
    return 0;
}