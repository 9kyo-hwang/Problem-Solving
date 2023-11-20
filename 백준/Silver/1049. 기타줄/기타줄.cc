#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<int> set(M), each(M);
  for (int i = 0; i < M; i++) {
    cin >> set[i] >> each[i];
  }

  sort(set.begin(), set.end());
  sort(each.begin(), each.end());

  if (set.front() > each.front() * 6) {
    cout << each.front() * N;
    return 0;
  }

  int answer = set.front() * (N / 6);
  if (each.front() * (N % 6) > set.front()) {
    answer += set.front();
  } else {
    answer += each.front() * (N % 6);
  }
  cout << answer;

  return 0;
}