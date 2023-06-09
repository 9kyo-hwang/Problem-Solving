#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {    
    vector<bool> visited(n, false);
    
    int answer = 0;
    for(int i = 0; i < n; i++) {
        if(visited[i])
            continue;
        
        queue<int> q;
        visited[i] = true;
        q.emplace(i);
        
        while(!q.empty()) {
            int src = q.front();
            q.pop();
            
            for(int j = 0; j < n; j++) {
                if(computers[src][j] == 0 || visited[j])
                    continue;
                
                visited[j] = true;
                q.emplace(j);
            }
        }
        answer++;
    }
    return answer;
}