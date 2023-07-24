#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

string skill_tree;

bool Judgement(string tree) {
    list<pair<char, bool>> l;
    for(const auto &ch : skill_tree)
        l.emplace_back(ch, false);
    
    for(const auto &ch : tree) {
        auto iter = find_if(l.begin(), l.end(), [ch](const pair<char, bool> &p) {
            return p.first == ch;
        });
        
        if(iter == l.end())
            continue;
        
        for(auto it = l.begin(); it != iter; ++it) {
            if((*it).second == false)
                return false;
        }
        
        (*iter).second = true;
    }
    
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    skill_tree = skill;
    int answer = 0;
    for(const auto &tree : skill_trees) {
        answer += Judgement(tree);
    }
    return answer;
}