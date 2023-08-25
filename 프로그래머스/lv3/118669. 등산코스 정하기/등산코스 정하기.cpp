#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 1e7 + 1;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<bool> is_gate(n + 1, false);
    for(const auto &g: gates) is_gate[g] = true;
    vector<bool> is_summit(n + 1, false);
    for(const auto &s : summits) is_summit[s] = true;
    
    vector<vector<pair<int, int>>> graph(n + 1);
    for(const auto &p : paths) {
        int i = p[0], j = p[1], w = p[2];
        
        graph[i].emplace_back(j, w);
        graph[j].emplace_back(i, w);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(const auto &g : gates) pq.emplace(0, g);
    
    vector<int> intensity(n + 1, INF);
    
    while(!pq.empty()) {
        const auto [si, src] = pq.top(); // si: source intensity
        pq.pop();
        
        if(is_summit[src])
            continue;
        
        if(intensity[src] < si)
            continue;
        
        for(const auto &[dst, di] : graph[src]) { // di: destination intensity
            if(is_gate[dst])
                continue;
            
            int new_i = max(si, di);
            if(intensity[dst] > new_i) {
                intensity[dst] = new_i;
                pq.emplace(new_i, dst);
            }
        }
    }
    
    int min_num = 0, min_i = INF;
    for(int i = 1; i <= n; i++) {
        if(is_summit[i] && intensity[i] < min_i) {
            min_num = i;
            min_i = intensity[i];
        }
    }
    
    return {min_num, min_i};
}