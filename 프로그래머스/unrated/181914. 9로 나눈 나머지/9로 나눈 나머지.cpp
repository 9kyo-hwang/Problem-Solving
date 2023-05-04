#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string number) {
    int answer = 0;
    for(const auto &ch : number)
        answer += ch - '0';
    return answer % 9;
}