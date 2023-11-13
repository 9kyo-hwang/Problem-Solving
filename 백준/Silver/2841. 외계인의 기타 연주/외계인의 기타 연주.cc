#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, P;
  cin >> N >> P;

  vector<int> pret[7];
  int answer = 0;
  while (N--) {
    int n, p;
    cin >> n >> p;

    while (!pret[n].empty() && pret[n].back() > p) {
      pret[n].pop_back();
      answer += 1;
    }

    if (pret[n].empty() || pret[n].back() < p) {
      pret[n].emplace_back(p);
      answer += 1;
      continue;
    }
  }

  cout << answer;

  return 0;
}