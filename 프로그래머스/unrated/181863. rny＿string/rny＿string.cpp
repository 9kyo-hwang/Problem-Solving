#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    for(const auto &ch : rny_string) {
        if(ch == 'm') {
            answer.push_back('r');
            answer.push_back('n');
            continue;
        }
        answer.push_back(ch);
    }
    return answer;
}