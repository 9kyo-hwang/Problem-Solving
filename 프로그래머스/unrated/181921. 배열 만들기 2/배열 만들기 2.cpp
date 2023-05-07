#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    queue<int> q;
    q.emplace(5);
    
    while(!q.empty()) {
        int num = q.front(); q.pop();
        if(num > r)
            break;
        
        if(num >= l)
            answer.emplace_back(num);
        
        q.push(num * 10 + 0);
        q.push(num * 10 + 5);
    }
    
    if(answer.empty())
        answer.emplace_back(-1);
    
    return answer;
}