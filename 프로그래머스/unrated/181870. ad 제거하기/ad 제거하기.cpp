#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for(const auto &str : strArr) {
        if(str.find("ad") == string::npos)
            answer.emplace_back(str);
    }
    return answer;
}