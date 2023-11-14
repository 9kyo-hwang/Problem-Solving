#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  queue<pair<int, int>> q;
  int time = 0;

  bool *visited = new bool[100001];
  memset(visited, false, 100001);

  q.emplace(N, time);
  visited[N] = true;

  while(!q.empty()) {
	int pos = q.front().first;
	int cur = q.front().second;
	q.pop();

	if(pos == K) {
	  cout << cur;
	  break;
	}

	cur++;

	if(pos * 2 <= 100000 && !visited[pos * 2]) {
	  visited[pos * 2] = true;
	  q.emplace(pos * 2, cur);
	}
	if(pos + 1 <= 100000 && !visited[pos + 1]) {
	  visited[pos + 1] = true;
	  q.emplace(pos + 1, cur);
	}
	if(pos - 1 >= 0 && !visited[pos - 1]) {
	  visited[pos - 1] = true;
	  q.emplace(pos - 1, cur);
	}
  }

  return 0;
}