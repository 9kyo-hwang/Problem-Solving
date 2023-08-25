#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

constexpr int INF = 1e7 + 1;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    set<int> gset(gates.begin(), gates.end());
    set<int> sset(summits.begin(), summits.end());
    
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
        
        if(sset.find(src) != sset.end()) // summit can't be a source
            continue;
        
        if(intensity[src] < si) // already calculated
            continue;
        
        for(const auto &[dst, di] : graph[src]) { // di: destination intensity
            if(gset.find(dst) != gset.end()) // gate can't be a destination
                continue;
            
            int new_i = max(si, di);
            if(new_i < intensity[dst]) {
                intensity[dst] = new_i;
                pq.emplace(new_i, dst);
            }
        }
    }
    
    int min_num = 0, min_i = INF;
    for(const int summit : sset) {
        if(intensity[summit] < min_i) {
            min_num = summit;
            min_i = intensity[summit];
        }
    }
    
    return {min_num, min_i};
}