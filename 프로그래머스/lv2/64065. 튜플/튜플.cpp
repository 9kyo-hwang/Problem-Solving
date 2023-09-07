#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    regex pattern(R"(\{(.*?)\})"); // 안쪽 중괄호 매칭
    sregex_iterator it(s.begin(), s.end(), pattern);
    sregex_iterator end;

    vector<vector<int>> v;
    while(it != end)
    {
        string match = it->str(1);
        if (v.empty()) // 첫 번째 match의 첫 번째 문자인 '{' 제거
            match = match.substr(1); 
        
        vector<int> inner_list;
        size_t pos = 0;
        while ((pos = match.find(',')) != string::npos)
        {
            inner_list.emplace_back(stoi(match.substr(0, pos)));
            match.erase(0, pos + 1);
        }
        inner_list.emplace_back(stoi(match));
        v.emplace_back(inner_list);
        
        ++it;
    }
    
    sort(v.begin(), v.end(), [](const vector<int> &p, const vector<int> &q) { return p.size() < q.size();});
    
    unordered_set<int> set;
    vector<int> answer;
    
    for(const auto &r: v)
    {
        for(const auto &c : r)
        {
            if(set.find(c) == set.end())
            {
                set.emplace(c);
                answer.emplace_back(c);
            }
        }
    }

    return answer;
}