#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Egg = pair<int,int>;  // S, W

#define S first
#define W second

int N;
vector<Egg> eggs;

int backtracking(int current = 0, int broken = 0) {
  if (current == N) {  // 3. 최근에 든 계란이 가장 오른쪽 계란이었다면
    return broken;
  }

  if (eggs[current].S <= 0 || broken == N - 1) {  // 2. 손에 든 계란이 깨졌거나 모든 계란이 깨졌다면
    return backtracking(current + 1, broken);
  }

  int count = 0;
  for (int next = 0; next < N; next++) {  // 
    if (current == next || eggs[next].S <= 0) continue;

    eggs[current].S -= eggs[next].W;
    eggs[next].S -= eggs[current].W;

    count = max(count, backtracking(current + 1, broken + (eggs[current].S <= 0) + (eggs[next].S <= 0)));

    eggs[current].S += eggs[next].W;
    eggs[next].S += eggs[current].W;
  }

  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  eggs.resize(N);
  
  for (auto &[S, W] : eggs) cin >> S >> W;

  cout << backtracking();

  return 0;
}