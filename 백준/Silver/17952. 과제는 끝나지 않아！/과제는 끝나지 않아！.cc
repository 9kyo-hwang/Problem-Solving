#include <iostream>
#include <vector>

using namespace std;

int main() { 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<pair<int, int>> stack;

  int N;
  cin >> N;

  int score = 0;
  while (N--) {
    int n;
    cin >> n;

    if (n == 0) {
      if (stack.empty()) continue;

      auto [a, t] = stack.back();
      stack.pop_back();
      t -= 1;

      if (t == 0) {
        score += a;
      } else {
        stack.emplace_back(a, t);
      }
    } else if (n == 1) {
      int A, T;
      cin >> A >> T;
      T -= 1;

      if (T == 0) {
        score += A;
      } else {
        stack.emplace_back(A, T);
      }
    }
  }
  cout << score;

  return 0;
}