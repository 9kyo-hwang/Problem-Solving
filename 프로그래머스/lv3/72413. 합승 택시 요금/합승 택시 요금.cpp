#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector graph(n + 1, vector(n + 1, INF));
    for(const auto& fare : fares) {
        int c = fare[0], d = fare[1], f = fare[2];
        
        graph[c][d] = f;
        graph[d][c] = f;
    }
    
    for(int i = 1; i <= n; i++)
        graph[i][i] = 0;
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    int answer = INF;
    for(int k = 1; k <= n; k++) {
        if(graph[s][k] == INF || graph[k][a] == INF || graph[k][b] == INF)
            continue;
        answer = min(answer, graph[s][k] + graph[k][a] + graph[k][b]);
    }
    return answer;
}