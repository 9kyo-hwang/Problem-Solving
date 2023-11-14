#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  deque<int> dq;
  dq.emplace_back(N);

  vector<int> dist(100001, 987654321);
  dist[N] = 0;

  int answer = 0;
  while (!dq.empty()) {
    int cur = dq.front();
    dq.pop_front();

    if (cur == K) {
      answer = dist[cur];
      break;
    }

    if (cur * 2 <= 100000 && dist[cur] < dist[cur * 2]) {
      dist[cur * 2] = dist[cur];
      dq.emplace_front(cur * 2);
    }

    if (cur - 1 >= 0 && dist[cur] + 1 < dist[cur - 1]) {
      dist[cur - 1] = dist[cur] + 1;
      dq.emplace_back(cur - 1);
    }

    if (cur + 1 <= 100000 && dist[cur] + 1 < dist[cur + 1]) {
      dist[cur + 1] = dist[cur] + 1;
      dq.emplace_back(cur + 1);
    }
  }

  cout << answer;
  return 0;
}