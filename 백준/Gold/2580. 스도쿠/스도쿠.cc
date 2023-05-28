#include <cstdio>
#include <vector>

#define EMPTY 0

using namespace std;

vector<pair<int, int>> v; // 빈칸 좌표를 기록하는 pair<int, int> 벡터
int arr[9][9];

void read_data() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == EMPTY)
                v.push_back({i, j});
        }
    }
}

void print_data() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

bool promising(int count) {
    int empty_x = v[count].first, empty_y = v[count].second;

    for(int col = 0; col < 9; col++) { // 행에 겹치는 숫자 있는 지 확인
        if((col != empty_y) && (arr[empty_x][col] == arr[empty_x][empty_y]))
            return false;
    }

    for(int row = 0; row < 9; row++) { // 열에 겹치는 숫자 있는 지 확인
        if((row != empty_x) && (arr[row][empty_y] == arr[empty_x][empty_y]))
            return false;
    }

    empty_x /= 3, empty_y /= 3; // 구역에 겹치는 숫자 있는 지 확인
    for(int row = empty_x * 3; row < empty_x * 3 + 3; row++) {
        for(int col = empty_y * 3; col < empty_y * 3 + 3; col++) {
            if((row != v[count].first) && (col != v[count].second) 
                && (arr[v[count].first][v[count].second] == arr[row][col]))
                return false;
        }
    }
    
    return true;
}

/**
 * 1. 빈칸이 모두 채워졌으면 완성된 스도쿠 보드를 출력하고 return
 * 2. 현재 칸이 빈칸이면 가로, 세로, 그 칸이 포함된 3 x 3 영역에 대해 1부터 9까지 중복 검사를 실시한다.
 * 3. 중복이 되지 않는다면 다음 빈칸에 대해 이 함수를 다시 수행한다.
 * @param n: 채운 빈칸의 수를 의미한다.
 */
bool sudoku(size_t count) {
    if(count == v.size())
        return true;

    for(int i = 1; i <= 9; i++) {
        arr[v[count].first][v[count].second] = i;
        if(!promising(count))
            continue;

        if(sudoku(count + 1))
            return true;
    }
    arr[v[count].first][v[count].second] = 0;
    return false;
}

int main() {
    read_data();

    if(sudoku(0))
        print_data();
    return 0;
}