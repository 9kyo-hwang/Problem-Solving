#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first; // data
    A[i].second = i; // index
  }

  sort(A.begin(), A.end());

  int count = 0;
  for(int i = 0; i < N; i++)
    count = max(count, A[i].second - i);

  cout << count + 1;

  return 0;
}