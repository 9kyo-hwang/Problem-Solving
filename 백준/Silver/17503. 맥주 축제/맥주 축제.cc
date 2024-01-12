#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, K;
  cin >> N >> M >> K;

  vector<pii> beers(K);

  for (auto &[level, priority] : beers) {
    cin >> priority >> level;
  }

  sort(beers.begin(), beers.end(), [](const pii& p, const pii& q) {
    if (p.first == q.first) {
      return p.second > q.second;
    }
    return p.first < q.first;
  });

  priority_queue<int, vector<int>, greater<>> pq;

  int m = 0, l = -1;
  for (const auto& [level, priority] : beers) {
    m += priority;
    pq.emplace(priority);

    if (pq.size() > N) {
      m -= pq.top();
      pq.pop();
    }

    if (pq.size() == N && m >= M) {
      l = level;
      break;
    }
  }

  cout << l;

  return 0;
}