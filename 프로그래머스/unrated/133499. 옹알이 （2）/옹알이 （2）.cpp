#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    regex duplicate("(ayaaya|yeye|woowoo|mama)");
    regex pattern("(aya|ye|woo|ma)");
    for(auto &str : babbling) {
        if(regex_search(str, duplicate))
            continue;
        
        str = regex_replace(str, pattern, "");
        
        if(str.empty())
            answer += 1;
    }
    return answer;
}