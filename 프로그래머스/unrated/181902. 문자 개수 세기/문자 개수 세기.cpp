#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    int interval = 'a' - 'Z';
    for(const auto& ch : my_string)
        'A' <= ch && ch <= 'Z' ? answer[ch - 'A']++ : answer[ch - 'A' - interval + 1]++;
    return answer;
}