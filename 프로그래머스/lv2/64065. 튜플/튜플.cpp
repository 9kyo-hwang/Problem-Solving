#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    bool inside = false;
    vector<vector<int>> v;
    for(int i = 1; i < s.length() - 1; i++)
    {   
        int j = i;
        while(s[j++] != '}');
        
        vector<int> inner_list;
        string inside_str(&s[i + 1], &s[j]);
        istringstream ss(inside_str);
        string buffer;
        while(getline(ss, buffer, ','))
        {
            int num = stoi(buffer);
            inner_list.emplace_back(num);
        }
        v.push_back(inner_list);
        
        i = j;
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