#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    while(arr.size() & arr.size() - 1) // 2의 제곱수는 비트로 표현 시 왼쪽 1비트만 1이고 나머지 0 -> 따라서 size와 size - 1을 and 연산해서 0이면 size는 2의 거듭제곱수
        arr.emplace_back(0);
    return arr;
}