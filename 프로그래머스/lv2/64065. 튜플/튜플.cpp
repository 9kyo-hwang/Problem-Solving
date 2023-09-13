#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

struct cmp 
{
    template <typename T>
    bool operator()(const T& l, const T& r) const
    {
        return l.second > r.second;
    }
};

vector<int> solution(string s) 
{
    unordered_map<int, int> map;
    
    string tmp;
    for(const char &c : s)
    {
        if(isdigit(c)) tmp += c;
        else if(tmp.length() > 0) // 숫자가 있는 경우만 map에 추가
        {
            map[stoi(tmp)]++;
            tmp.clear();
        }
    }
    
    set<pair<int, int>, cmp> S(map.begin(), map.end());
    vector<int> answer;
    for(const auto &[num, freq] : S) 
        answer.emplace_back(num);
    return answer;
}