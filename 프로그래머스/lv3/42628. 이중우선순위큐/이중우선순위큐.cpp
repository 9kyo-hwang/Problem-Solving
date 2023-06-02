#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    
    for(auto& str: operations) {
        char op = str[0];
        str.erase(0, 2);
        int n = stoi(str);
        
        if(op == 'I') {
            ms.emplace(n);
        } else if(op == 'D') {
            if(ms.empty())
                continue;
            
            if(n == 1) {
                ms.erase(--ms.end());
            } else if(n == -1) {
                ms.erase(ms.begin());
            }
        }
    }
    
    vector<int> answer;
    if(ms.empty()) {
        answer.emplace_back(0);
        answer.emplace_back(0);
    } else {
        answer.emplace_back(*(--ms.end()));
        answer.emplace_back(*(ms.begin()));
    }
    return answer;
}