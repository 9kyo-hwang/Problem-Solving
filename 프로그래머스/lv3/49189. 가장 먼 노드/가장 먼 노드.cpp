#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    for(const auto& e : edge) {
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
    }
    
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    
    q.emplace(1, 0);
    visited[1] = true;
    int max_depth = 0;
    int answer = 0;
    while(!q.empty()) {
        const auto &[src, depth] = q.front();
        q.pop();
        
        if(depth > max_depth) {
            max_depth = depth;
            answer = 1;
        } else if(depth == max_depth) {
            answer += 1;
        }
        
        for(const auto& dst : graph[src]) {
            if(!visited[dst]) {
                visited[dst] = true;
                q.emplace(dst, depth + 1);
            }
        }
    }
    
    return answer;
}