#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
using psi = pair<string, int>;

void combination(unordered_map<string, int> &map, const string &str, vector<bool> &visited, int begin, int n, int r) // nCr
{
    if(r == 0)
    {
        string tmp;
        for(int i = 0; i < n; i++)
        {
            if(visited[i]) 
                tmp += str[i];
        }
        sort(tmp.begin(), tmp.end());
        
        map[tmp]++;
        return;
    }
    
    for(int i = begin; i < n; i++)
    {
        visited[i] = true;
        combination(map, str, visited, i + 1, n, r - 1);
        visited[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> courses) 
{
    vector<string> answer;
    for(const int course : courses)
    {
        unordered_map<string, int> map;
        
        for(const string &order : orders)
        {
            int n = order.length();
            if(n < course) continue;
            
            vector<bool> visited(n, false);
            combination(map, order, visited, 0, n, course);
        }
        
        if(map.empty()) continue;
        
        vector<psi> v(map.begin(), map.end());
        sort(v.begin(), v.end(), [](const psi &a, const psi &b)
             {
                 return a.second > b.second;
             });
        
        int max_order = v[0].second;
        if(max_order == 1) continue;
        
        for(const auto &[menu, num_order] : v)
        {
            if(num_order < max_order) break;
            answer.emplace_back(menu);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}