#include <iostream>

using namespace std;

int get_count(int N) {
    int count = 0;
    while(N >= 0) {
        if(N % 5 == 0) { // 5의 배수는 곧 5kg으로 담는 것이 최소 개수
            count += N / 5; // 5로 나눈 몫을 더하고 즉시 리턴
            return count;
        }
        N -= 3; // 5의 배수가 아니라면 3 빼고 3kg 봉지 1개 추가
        count++;
    }

    return -1;
}

int main() {
    int N;
    cin >> N;

    int count = get_count(N);

    cout << count;
    
    return 0;
}