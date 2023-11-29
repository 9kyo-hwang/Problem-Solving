#include <iostream>
#include <queue>

#define idx first
#define num second

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, L;
  cin >> N >> L;

  deque<pair<int, int>> dq;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;

    while (!dq.empty() && dq.back().num >= A) {
      dq.pop_back();
    }

    dq.emplace_back(i, A);
    while (!dq.empty() && dq.front().idx <= i - L) {
      dq.pop_front();
    }

    cout << dq.front().num << "\n";
  }

  return 0;
}