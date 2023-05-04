#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    while(true) {
        answer.emplace_back(n);
        if(n == 1)
            break;
        n = (n % 2 == 0 ? n / 2 : 3 * n + 1);
    }
    return answer;
}