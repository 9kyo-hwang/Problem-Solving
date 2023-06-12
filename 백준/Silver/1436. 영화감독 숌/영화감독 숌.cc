#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    // 666부터 시작
    int num = 666, series = 0;
    while(true) {
        int tmp = num;

        do { // 1000으로 나눈 나머지가 666(연속된 6 3개)이면 다음 시리즈
            if(tmp % 1000 == 666) {
                series++;
                break;
            }
        } while(tmp /= 10);

        if(series == N) { // 그 시리즈가 내가 찾는 시리즈와 같은 경우 break
            cout << num;
            break;
        }

        num++; // 1씩 계속 증가시킴
    }

    return 0;
}