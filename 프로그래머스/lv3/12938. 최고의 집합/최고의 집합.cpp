#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s)
        return {-1};

    // 곱 최대 -> 최대한 중앙값으로 채우기
    vector<int> answer;
    do {
        answer.emplace_back(s / n);
        s -= s / n;
    } while(--n);
    
    return answer;
}