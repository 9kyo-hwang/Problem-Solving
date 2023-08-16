#include <string>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX = 1e9;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<vector<int>> adj_lists(n + 1);
    for(const auto &road : roads) {
        int src = road[0], dst = road[1];
        
        adj_lists[src].emplace_back(dst);
        adj_lists[dst].emplace_back(src);
    }
    
    vector<int> dists(n + 1, MAX);
    queue<pair<int, int>> q;

    q.emplace(destination, 0);
    dists[destination] = 0;
    while(!q.empty()) {
        const auto [src, cost] = q.front();
        q.pop();
        
        for(const auto &dst : adj_lists[src]) {
            if(cost + 1 < dists[dst]) {
                dists[dst] = cost + 1;
                q.emplace(dst, cost + 1);
            }
        }
    }
    
    vector<int> answer;
    for(const auto &src: sources) {
        answer.emplace_back(dists[src] == MAX ? -1 : dists[src]);
    }
    return answer;
}