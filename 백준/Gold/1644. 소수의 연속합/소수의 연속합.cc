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

  vector<int> primes;
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      primes.emplace_back(i);
    }
  }

  deque<int> dq;
  int answer = 0, summation = 0;
  for (const int prime : primes) {
    summation += prime;
    dq.emplace_back(prime);

    if (summation < N) {
      continue;
    } else if (summation == N) {
      answer += 1;
      continue;
    } else {
      while (!dq.empty() && summation > N) {
        summation -= dq.front();
        dq.pop_front();
      }

      if (summation == N) {
        answer += 1;
      }
    }
  }

  cout << answer;

  return 0;
}