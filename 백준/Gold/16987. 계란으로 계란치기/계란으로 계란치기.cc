#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Egg = pair<int,int>;  // S, W

#define S first
#define W second

int N;
vector<Egg> eggs;

int answer = 0;
void backtracking(int index = 0) {
  if (index > N) return;

  for (int i = 0; i < N; i++) {
    if (index == i || eggs[i].S <= 0) continue;

    if (eggs[index].first <= 0) {
      backtracking(index + 1);
    } else {
      eggs[index].S -= eggs[i].W;
      eggs[i].S -= eggs[index].W;

      backtracking(index + 1);

      eggs[index].S += eggs[i].W;
      eggs[i].S += eggs[index].W;
    }
  }

  int count = 0;
  for (int i = 0; i < N; i++) {
    if (eggs[i].S <= 0) {
      count += 1;
    }
  }

  answer = max(answer, count);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  eggs.resize(N);
  
  for (auto &[S, W] : eggs) cin >> S >> W;

  backtracking();
  cout << answer;

  return 0;
}