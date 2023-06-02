#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int answer = 0;
    while(!pq.empty()) {
        int a = pq.top();
        pq.pop();
        
        if(a >= K) {
            break;
        } else if(pq.empty()) {
            answer = -1;
            break;
        }
        
        int b = pq.top();
        pq.pop();
        
        pq.emplace(a + b * 2);
        answer++;
    }
    return answer;
}