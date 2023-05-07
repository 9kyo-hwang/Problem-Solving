#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for(const auto& str : picture) {
        for(int i = 0; i < k; i++) {
            string line;
            for(const auto& ch : str) {
                for(int j = 0; j < k; j++) {
                    line.push_back(ch);
                }
            }
            answer.emplace_back(line);
        }
    }
    return answer;
}