#include <iostream>
#include <vector>
#include <queue>

#define null 0
#define integer(x) static_cast<int>(EColor::x)

using namespace std;

enum class EColor {
    WHITE,
    GRAY,
    BLACK,
};

int N;
vector<vector<int>> graph;
vector<bool> is_cycle;

void bfs(deque<int> &dq, vector<bool> &visited, vector<int> &dists) {
  while (!dq.empty()) {
    const int v = dq.front();
    dq.pop_front();

    for (const auto &w : graph[v]) {
      if (visited[w]) {
        continue;
      }

      visited[w] = true;
      dists[w] = dists[v] + 1;
      dq.emplace_back(w);
    }
  }
}

void bfs_util() {
  deque<int> dq;
  vector<bool> visited(N + 1, false);
  for (int i = 1; i <= N; ++i) {
    if (is_cycle[i]) {
      dq.emplace_back(i);
      visited[i] = true;
    }
  }

  vector<int> dists(N + 1, 0);

  bfs(dq, visited, dists);

  for (int i = 1; i <= N; ++i) {
    cout << dists[i] << " ";
  }
}

bool dfs(vector<int> &color, vector<int> &parents, int v = 1) {
  color[v] = integer(GRAY);
  for (const auto &w : graph[v]) {
    if (color[w] == integer(WHITE)) {
      parents[w] = v;
      if (dfs(color, parents, w)) {
        return true;
      }
    } else if (color[w] == integer(GRAY) && parents[v] != w) {
      is_cycle[v] = true;
      while (v != w) {
        is_cycle[parents[v]] = true;
        v = parents[v];
      }
      return true;
    }
  }
  color[v] = integer(BLACK);
  return false;
}

void dfs_util() {
  vector<int> color(N + 1, integer(WHITE));
  vector<int> parents(N + 1, null);
  dfs(color, parents);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  graph.resize(N + 1);
  is_cycle.assign(N + 1, false);

  for (int i = 1; i <= N; ++i) {
    int a, b;
    cin >> a >> b;

    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  dfs_util();
  bfs_util();

  return 0;
}