#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i = x; answer.size() != n; i += x)
        answer.emplace_back(i);
    return answer;
}