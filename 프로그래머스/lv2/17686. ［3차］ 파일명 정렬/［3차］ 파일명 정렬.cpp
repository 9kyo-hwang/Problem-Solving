#include <string>
#include <vector>
#include <cctype>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;
using fname = tuple<string, string, string>;

vector<string> solution(vector<string> files) {
    string HEAD, NUMBER, TAIL;
    vector<fname> v;
    for(const string &file : files)
    {
        int i = 0, j = 0;
        
        while(!isdigit(file[j])) j++;
        HEAD = string(&file[i], &file[j]);
        i = j;
        
        while(isdigit(file[j])) j++;
        NUMBER = string(&file[i], &file[j]);
        i = j;
        
        TAIL = file.substr(i);
        
        v.emplace_back(HEAD, NUMBER, TAIL);
    }
    
    stable_sort(v.begin(), v.end(), [](const fname &a, const fname &b) {
        const auto &[h1, n1, t1] = a;
        const auto &[h2, n2, t2] = b;
        
        int result = strcasecmp(h1.c_str(), h2.c_str());
        if(result == 0) return stoi(n1) < stoi(n2);
        return result < 0;
    });
    
    vector<string> answer;
    for(const auto &[head, number, tail] : v)
    {
        answer.emplace_back(head + number + tail);
    }
    return answer;
}