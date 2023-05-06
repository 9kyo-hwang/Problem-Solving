#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    for(auto &num : num_list) {
        while(num > 1) {
            num /= 2; // 홀수여도 어차피 내림 연산이 적용됨.
            answer++;
        }
    }
    return answer;
}