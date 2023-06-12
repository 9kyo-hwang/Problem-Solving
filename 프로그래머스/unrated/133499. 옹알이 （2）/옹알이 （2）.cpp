#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> words = {"aya", "ye", "woo", "ma"};
unordered_set<string> set;

void Combinations(const string &current) {
    if(current.length() > 30)
        return;
    
    if(!current.empty())
        set.emplace(current);
    
    for(const auto &word: words) {
        if(current.empty() || current.substr(current.length() - 2) != word.substr(word.length() - 2))
            Combinations(current + word);
    }
}

int solution(vector<string> babbling) {
    int answer = 0;
    Combinations("");
    for(const auto &str : babbling) {
        if(set.find(str) != set.end())
            answer += 1;
    }
    return answer;
}