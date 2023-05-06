#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for(const auto& str : intStrs) {
        int num = stoi(str.substr(s, l));
        if(num > k)
            answer.emplace_back(num);
    }
    return answer;
}