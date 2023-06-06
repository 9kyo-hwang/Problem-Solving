#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
  int answer = n + 1;
  for(int i = 0; i < wires.size(); i++) { // disconnected wire's index
    vector<vector<int>> graph(n + 1);
    for(int j = 0; j < wires.size(); j++) { // make graph
      if(i == j)
        continue;

      graph[wires[j][0]].emplace_back(wires[j][1]);
      graph[wires[j][1]].emplace_back(wires[j][0]);
    }

    vector<bool> visited(n + 1, false);
    vector<int> components;
    for(int k = 1; k <= n; k++) { // graph traversal
      if(visited[k])
        continue;

      queue<int> q;

      visited[k] = true;
      q.emplace(k);
      int count = 1;

      while(!q.empty()) {
        int src = q.front();
        q.pop();

        for(const auto& dst : graph[src]) {
          if(!visited[dst]) {
            visited[dst] = true;
            q.emplace(dst);
            count++;
          }
        }
      }
      components.emplace_back(count);
    }
    
    answer = min(answer, abs(components[0] - components[1]));
  }
    return answer;
}