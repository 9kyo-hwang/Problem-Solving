#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;

vector<int> solution(string s) {
    unordered_map<int, int> map;
    
    string tmp;
    for(const char &c : s)
    {
        if('0' <= c && c <= '9') tmp += c;
        else if(tmp.length() > 0) // 숫자가 있는 경우만 map에 추가
        {
            map[stoi(tmp)]++;
            tmp.clear();
        }
    }
    
    vector<pii> v(map.begin(), map.end());
    sort(v.begin(), v.end(), [](const pii &p, const pii &q)
         {
             return p.second > q.second;
         });
    
    vector<int> answer;
    for(const auto &[num, freq] : v) 
        answer.emplace_back(num);
    return answer;
}