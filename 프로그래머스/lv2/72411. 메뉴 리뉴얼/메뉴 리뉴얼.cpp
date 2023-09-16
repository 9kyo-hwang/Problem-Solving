#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using psi = pair<string, int>;

unordered_map<string, int> map;
vector<bool> visited;

void combination(const string &str, int index, int r) // nCr
{
    if(r == 0)
    {
        string tmp;
        for(int i = 0; i < str.length(); i++)
        {
            if(visited[i]) 
                tmp += str[i];
        }
        sort(tmp.begin(), tmp.end());
        
        map[tmp]++;
        return;
    }
    
    for(int i = index; i < str.length(); i++)
    {
        visited[i] = true;
        combination(str, i + 1, r - 1);
        visited[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> courses) 
{
    vector<string> answer;
    for(const int course : courses)
    {
        map.clear();
        for(const string &order : orders)
        {
            int n = order.length();
            if(n < course) continue;

            visited.assign(n, false);
            combination(order, 0, course);
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