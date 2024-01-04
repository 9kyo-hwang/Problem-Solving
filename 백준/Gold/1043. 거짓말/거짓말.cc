#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> parents;

int find(int x) {
  while (x != parents[x]) {
    parents[x] = parents[parents[x]];
    x = parents[x];
  }

  return parents[x];
}

void unite(int x, int y) { 
  x = find(x);
  y = find(y);

  if (x == y) {
    return;
  }

  if (x < y) {
    parents[y] = x;
  } else if(x > y) {
    parents[x] = y;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;  // human, party

  parents.resize(N + 1);
  iota(parents.begin(), parents.end(), 0);

  int num_true;
  cin >> num_true;

  while (num_true--) {
    int t;
    cin >> t;

    parents[t] = 0;
  }

  vector<vector<int>> parties(M + 1);
  for (int i = 1; i <= M; i++) {
    int m;
    cin >> m;

    while (m--) {
      int num;
      cin >> num;

      parties[i].emplace_back(num);
    }
  }

  for (const auto& party : parties) {
    if (party.size() <= 1) {
      continue;
    }

    for (int i = 0; i < party.size() - 1; i++) {
      unite(party[i], party[i + 1]);
    }
  }

  int answer = 0;
  for (const auto& party : parties) {
    if (party.size() < 1) {
      continue;
    }

    bool flag = false;
    for (const auto& member : party) {
      if (find(member) == 0) {
        flag = true;
        break;
      }
    }
    
    if (!flag) {
      answer += 1;
    }
  }

  cout << answer;

  return 0;
}