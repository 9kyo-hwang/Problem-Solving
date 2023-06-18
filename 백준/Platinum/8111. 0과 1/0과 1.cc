#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    if(N == 1) {
      cout << 1 << "\n";
      continue;
    }

    vector<bool> visited(20001, false);

    queue<pair<string, int>> q;
    q.emplace("1", 1);

    string result = "BRAK";

    while(!q.empty()) {
      const auto [str, num] = q.front();
      q.pop();

      for(const int i : {0, 1}) {
        int next = (num * 10 + i) % N;

        if(visited[next])
          continue;

        if(next == 0) {
          result = str + to_string(i);
          break;
        }

        visited[next] = true;
        q.emplace(str + to_string(i), next);
      }
    }

    cout << result << "\n";
  }

  return 0;
}