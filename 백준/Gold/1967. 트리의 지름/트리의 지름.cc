#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<pair<int, int>>> adj_list;

pair<int, int> FindFarthestNode(int begin) {
  vector<int> distances(N + 1, 0);
  vector<bool> visited(N + 1, false);
  queue<int> q;

  q.emplace(begin);
  visited[begin] = true;

  int max_dist = 0;
  int farthest_node = begin;

  while(!q.empty()) {
    int parent = q.front();
    q.pop();

    for(const auto &[child, weight] : adj_list[parent]) {
      if(visited[child])
        continue;

      visited[child] = true;
      distances[child] = distances[parent] + weight;

      if(distances[child] > max_dist) {
        max_dist = distances[child];
        farthest_node = child;
      }

      q.emplace(child);
    }
  }

  return {farthest_node, max_dist};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;

  adj_list = vector<vector<pair<int, int>>>(N + 1);
  for(int i = 0; i < N - 1; i += 1) {
    int parent, child, weight;
    cin >> parent >> child >> weight;

    adj_list[parent].emplace_back(child, weight);
    adj_list[child].emplace_back(parent, weight);
  }

  const auto &[n1, w1] = FindFarthestNode(1);
  const auto &[n2, w2] = FindFarthestNode(n1);

  cout << w2;

  return 0;
}