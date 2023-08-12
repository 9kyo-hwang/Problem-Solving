#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq(works.begin(), works.end());
    
    while(pq.top() > 0 && n--) {
        int top = pq.top();
        pq.pop();
        pq.emplace(top - 1);
    }
    
    long long answer = 0;
    while(!pq.empty()) {
        int top = pq.top();
        answer += top * top;
        pq.pop();
    }
    return answer;
}