#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> strs;
    for(const auto& i : numbers)
        strs.emplace_back(to_string(i));
    
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    
    string answer = "";
    for(const auto& str : strs)
        answer += str;
    
    return answer[0] == '0' ? "0" : answer;
}