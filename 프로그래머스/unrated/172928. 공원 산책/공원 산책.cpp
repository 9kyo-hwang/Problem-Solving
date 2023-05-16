#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    const int H = park.size();
    const int W = park[0].length();
    
    vector<vector<int>> maze(H, vector<int>(W, 0));
    int x = 0, y = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(park[i][j] == 'X')
                maze[i][j] = 1;
            else if(park[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }
    
    for(const auto& str : routes) {
        const char dir = str[0];
        const int step = str[2] - '0';
                
        int nx = x, ny = y;
        switch(dir) {
            case 'N': nx -= step; break;
            case 'E': ny += step; break;
            case 'S': nx += step; break;
            case 'W': ny -= step; break;
        }
        
        if(nx < 0 || nx >= H || ny < 0 || ny >= W)
            continue;
        
        bool flag = false;
        if(x != nx) {
            if(x < nx) {
                for(int r = x; r <= nx; r++) {
                    if(maze[r][y] == 1) {
                        flag = true;
                        break;
                    }
                }
            } else {
                for(int r = x; r >= nx; r--) {
                    if(maze[r][y] == 1) {
                        flag = true;
                        break;
                    }
                }
            }
        } else {
            if(y < ny) {
                for(int c = y; c <= ny; c++) {
                    if(maze[x][c] == 1) {
                        flag = true;
                        break;
                    }
                }
            } else {
                for(int c = y; c >= ny; c--) {
                    if(maze[x][c] == 1) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        
        if(flag)
            continue;
        
        x = nx;
        y = ny;
    }
    
    return {x, y};
}