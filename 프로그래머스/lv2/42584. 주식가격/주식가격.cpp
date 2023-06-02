#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    priority_queue<pair<int, int>> pq;
    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        answer[i] = n - i - 1;
    }
    
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().first > prices[i]) {
            answer[pq.top().second] = i - pq.top().second;
            pq.pop();
        }
        pq.emplace(prices[i], i);
    }
    return answer;
}