#include <iostream>
#include <vector>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define PII pair<int, int>
#define INF INT32_MAX

using namespace std;

int N, E;
vector<vector<PII>> adj_lists;

int Dijkstra(int begin, int end) {
  priority_queue<PII, vector<PII >, greater<>> pq;
  vector<int> distances(N + 1, INF);

  pq.emplace(0, begin);
  distances[begin] = 0;

  while (!pq.empty()) {
    const auto [weight, src] = pq.top();
    pq.pop();

    if (weight > distances[src])
      continue;

    for (const auto &[dst, dist] : adj_lists[src]) {
      int new_dist = weight + dist;
      if (new_dist < distances[dst]) {
        distances[dst] = new_dist;
        pq.emplace(new_dist, dst);
      }
    }
  }

  return distances[end];
}

int main() {
  FASTIO

  cin >> N >> E;

  adj_lists = vector<vector<PII>>(N + 1);
  while (E--) {
    int a, b, c;
    cin >> a >> b >> c;

    adj_lists[a].emplace_back(b, c);
    adj_lists[b].emplace_back(a, c);
  }

  int v1, v2;
  cin >> v1 >> v2;

  int p1 = -1, p2 = -1;

  int d1 = Dijkstra(1, v1), d2 = Dijkstra(v1, v2), d3 = Dijkstra(v2, N);
  if (d1 < INF && d2 < INF && d3 < INF)
    p1 = d1 + d2 + d3;

  d1 = Dijkstra(1, v2), d2 = Dijkstra(v2, v1), d3 = Dijkstra(v1, N);
  if (d1 < INF && d2 < INF && d3 < INF)
    p2 = d1 + d2 + d3;

  cout << (p1 < p2 ? p1 : p2);
  return 0;
}