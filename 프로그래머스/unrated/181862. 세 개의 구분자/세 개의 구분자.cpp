#include <string>
#include <vector>
#include <regex>

using namespace std;

vector<string> split(string s, string pattern = " ") {
    regex re(pattern);
    sregex_token_iterator it(s.begin(), s.end(), re, -1), end;
    return vector<string>(it, end);
}

vector<string> solution(string myStr) {
    vector<string> answer = split(myStr, R"(a|b|c)");
    auto it = answer.begin();
    while(it != answer.end()) {
        if((*it).empty())
            it = answer.erase(it);
        else it++;
    }
    if(answer.empty())
        answer.emplace_back("EMPTY");
    return answer;
}