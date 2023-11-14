#include <iostream>
#include <algorithm>

using namespace std;

int DFS(int N, int K) {
  if (K <= N) {
    return N - K;
  }

  if (K == 1) {
    return 1;
  }

  if (K % 2 == 1) {
    return 1 + min(DFS(N, K - 1), DFS(N, K + 1));
  }

  return min(K - N, DFS(N, K / 2));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  cout << DFS(N, K);

  return 0;
}