#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(vector<int> priorities, int location) {
    list<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); i++)
        q.emplace_back(i, priorities[i]);
    
    int answer = 1;
    while(!q.empty()) {
        const auto& [index, priority] = q.front();
        q.pop_front();
        
        bool flag = false;
        for(const auto& [i, p] : q) {
            if(p > priority) {
                q.emplace_back(index, priority);
                flag = true;
                break;
            }
        }
        
        if(!flag) {
            if(index == location)
                break;
            answer++;
        }
    }
    
    return answer;
}