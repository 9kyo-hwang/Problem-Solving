#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector is_prime(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  deque<int> dq;
  int answer = 0, summation = 0;
  for (int i = 2; i <= N; ++i) {
    if (!is_prime[i]) {
      continue;
    }

    summation += i;
    dq.emplace_back(i);

    if (summation <= N) {
      if (summation == N) {
        answer += 1;
      }
      continue;
    } 

    while (!dq.empty() && summation > N) {
      summation -= dq.front();
      dq.pop_front();
    }

    if (summation == N) {
      answer += 1;
    }
  }

  cout << answer;

  return 0;
}