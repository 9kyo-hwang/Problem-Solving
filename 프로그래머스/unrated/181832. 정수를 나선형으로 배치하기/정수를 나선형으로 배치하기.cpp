#include <string>
#include <vector>

using namespace std;

int OFFSET[][2] = {
    {0, 1}, // E
    {1, 0}, // S
    {0, -1}, // W
    {-1, 0} // N
};

vector<vector<int>> solution(int n) {
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int i = 0, j = 0;
    int num = 1;
    
    while(num <= n * n) {
        for(int dir = 0; dir < 4; dir++) {
            while(0 <= i && i < n && 0 <= j && j < n && arr[i][j] == 0) {
                arr[i][j] = num++;
                
                switch(dir) {
                    case 0: j++; break;
                    case 1: i++; break;
                    case 2: j--; break;
                    case 3: i--; break;
                }
            }
            
            switch(dir) {
                case 0: j--, i++; break;
                case 1: i--, j--; break;
                case 2: j++, i--; break;
                case 3: i++, j++; break;
            }
        }
    }
    
    return arr;
}