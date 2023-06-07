#include <bits/stdc++.h>
using namespace std;

int N, r, c;
int visited = 0;

bool move_zeta(int size, int x, int y) {
    /**
     * 현재 사분면에 r, c 좌표가 존재하지 않는다면
     * 방문 횟수(visited)를 현재 사분면 크기(정사각형 넓이, 즉 size * size)만큼 증가시키고 
     * return false;
     */
    if(r < x || r >= x + size || c < y || c >= y + size) {
        visited += size * size;
        return false;
    }
    /**
     * 현재 좌표(x, y)가 r, c 좌표와 동일하다면
     * return true; 
     */
    else if(x == r && y == c) {
        return true;
    }
    else {
        return move_zeta(size / 2, x, y) // 1사분면 체크
        || move_zeta(size / 2, x, y + size / 2) // 2사분면 체크
        || move_zeta(size / 2, x + size / 2, y) // 3사분면 체크
        || move_zeta(size / 2, x + size / 2, y + size / 2); // 4사분면 체크
    }
}

int main() {
    cin >> N >> r >> c;

    // 최초 크기: N x N, 최초 좌표: 0, 0
    // 함수 결과가 true이면 r, c 좌표의 방문 순서(visited)를 구한 것.
    if(move_zeta(pow(2, N), 0, 0))
        cout << visited << "\n";

    return 0;
}