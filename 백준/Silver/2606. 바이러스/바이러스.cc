#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int get_component(vector<vector<int>> &graph) {
  vector<int> visited(graph.size(), 0);
  queue<int> q;
  q.emplace(1);
  visited[1] = 1;

  int count = 0;
  while(!q.empty()) {
	int node = q.front();
	q.pop();

	for(auto &i : graph[node]) {
	  if(visited[i] == 0) {
		count++;
		visited[i] = 1;
		q.emplace(i);
	  }
	}
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> graph(N + 1);

  while(M--) {
	int a, b;
	cin >> a >> b;
	graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  int num = get_component(graph);
  cout << num;

  return 0;
}