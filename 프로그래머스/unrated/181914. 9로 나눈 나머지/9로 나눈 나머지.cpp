#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string number) {
    int answer = 0;
    reverse(number.begin(), number.end());
    for(const auto &ch : number) {
        answer += ch - '0';
        answer %= 9;
    }
    return answer;
}