#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<vector<int>> graph(N + 1);
  
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;

    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  deque<int> q;
  vector visited(N + 1, false);
  
  vector<int> parents(N + 1);
  iota(parents.begin(), parents.end(), 0);

  q.emplace_back(1);
  visited[1] = true;

  while (!q.empty()) {
    const int from = q.front();
    q.pop_front();

    for (const auto &to : graph[from]) {
      if (visited[to]) {
        continue;
      }

      visited[to] = true;
      parents[to] = from;
      q.emplace_back(to);
    }
  }

  for (int i = 2; i <= N; ++i) {
    cout << parents[i] << "\n";
  }

  return 0;
}