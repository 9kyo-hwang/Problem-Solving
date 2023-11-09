#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<int> indegrees(N + 1, 0);
  vector<vector<int>> graph(N + 1);

  while (M--) {
    int n;
    cin >> n;

    vector<int> singer(n);
    for (int &i : singer)
      cin >> i;

    for (int i = n - 1; i > 0; i--) {
      graph[singer[i - 1]].emplace_back(singer[i]);
      indegrees[singer[i]]++;
    }
  }

  queue<int> q;
  for (int i = 1; i <= N; i++) {
    if (indegrees[i] == 0) q.emplace(i);
  }

  vector<int> answer;
  bool flag = true;
  while (N--) {
    if (q.empty()) {
      flag = false;
      break;
    }

    int from = q.front();
    q.pop();
    answer.emplace_back(from);

    for (const int to : graph[from]) {
      indegrees[to]--;
      if (indegrees[to] == 0) {
        q.emplace(to);
      }
    }
  }

  if (!flag) {
    cout << 0;
  } else {
    for (const int i : answer) cout << i << "\n";
  }

  return 0;
}