#include <cstdio>

#define MAX 20

char data[MAX][MAX];
int R, C;
bool visited[26]; // numbers of alphabet
int offset[][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

bool is_wall(int x, int y) {
    return (x < 0 || x >= R || y < 0 || y >= C);
}

bool is_path(int x, int y) {
    visited[data[x][y] - 'A'] = true; // temporarily marking for check pathway
    for(int dir = 0; dir < 4; dir++) {
        int next_x = x + offset[dir][0], next_y = y + offset[dir][1];
        if(!is_wall(next_x, next_y) && !visited[data[next_x][next_y] - 'A']) {
            visited[data[x][y] - 'A'] = false;
            return true;
        }
    }
    visited[data[x][y] - 'A'] = false;
    return false;
}

int alphabets(int x, int y, int count) {
    if(is_wall(x, y) || visited[data[x][y] - 'A'])  {  // check current position
        return -1;
    }
    else if(!is_path(x, y)) { // check next 4-direction position
        return count + 1;
    }
    else {
        visited[data[x][y] - 'A'] = true; // marking current position
        count++; // plus 1
        int max = -1;
        for(int dir = 0; dir < 4; dir++) {
            int tmp = alphabets(x + offset[dir][0], y + offset[dir][1], count);

            if(tmp > max)
                max = tmp;
        }
        visited[data[x][y] - 'A'] = false; // release marking
        return max;
    }
}

void read_data() {
    scanf("%d%d ", &R, &C);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &data[i][j]);
        }
    }
}

int main() {
    read_data();
    printf("%d\n", alphabets(0, 0, 0));
    return 0;
}