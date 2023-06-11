#include <string>
#include <vector>

using namespace std;

constexpr int INF = 987654321;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for(int i = 1; i <= n; i++) 
        graph[i][i] = 0; // myself
    
    for(const auto &edge : results) {
        graph[edge[0]][edge[1]] = 1;
        graph[edge[1]][edge[0]] = -1;
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
             for(int j = 1; j <= n; j++) {            
                 if(graph[i][k] == 1 && graph[k][j] == 1) { // i > k && k > j -> i > j
                     graph[i][j] = 1;
                 } else if(graph[i][k] == -1 && graph[k][j] == -1) { // i < k && k < j -> i < j
                     graph[i][j] = -1;
                 }
             }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        bool disconnected = false;
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] == INF) {
                disconnected = true;
                break;
            }
        }
        
        if(!disconnected)
            answer += 1;
    }
    
    return answer;
}