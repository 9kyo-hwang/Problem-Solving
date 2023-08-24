#include <string>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 2e7;

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<pair<int, int>>> graph(N + 1);
    for(const auto &r : road) {
        int a = r[0], b = r[1], c = r[2];
        
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> distance(N + 1, INF);
    
    pq.emplace(0, 1);
    distance[1] = 0;
    
    while(!pq.empty()) {
        const auto [w, src] = pq.top();
        pq.pop();
        
        if(distance[src] < w)
            continue;
        
        for(const auto &[dst, d] : graph[src]) {
            int cost = w + d;
            if(cost < distance[dst]) {
                distance[dst] = cost;
                pq.emplace(cost, dst);
            }
        }
    }
    
    
    int answer = 0;
    for(int i = 1; i <= N; i++) {
        if(distance[i] <= K) {
            answer += 1;
        }
    }
    return answer;
}