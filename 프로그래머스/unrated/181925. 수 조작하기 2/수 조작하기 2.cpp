#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    int start = numLog[0];
    for(const auto &i : numLog) {
        if(i - start == 1)
            answer += "w";
        else if(i - start == -1)
            answer += "s";
        else if(i - start == 10)
            answer += "d";
        else if(i - start == -10)
            answer += "a";
        start = i;
    }
    return answer;
}