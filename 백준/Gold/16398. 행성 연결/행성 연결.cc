#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class UnionFind {
 public:
  UnionFind(int n) { 
    p.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
    size.assign(n + 1, 1);
  }

  ~UnionFind() = default;

  bool Union(int u, int v) { 
    int x = Find(u);
    int y = Find(v);
    
    if (x == y) 
      return false;

    if (size[x] > size[y]) {
      p[y] = x;
      size[x] += size[y];
    } else {
      p[x] = y;
      size[y] += size[x];
    }

    return true;
  }

 private:
  vector<int> p, size;
     
  int Find(int x) {
    while (x != p[x]) {
      p[x] = p[p[x]];
      x = p[x];
    }
    return x;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<vector<int>> C(N, vector<int>(N, 0));
  for (auto &r : C) {
    for (auto &c : r) {
      cin >> c;
    }
  }

  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      edges.emplace_back(C[i][j], i, j);
    }
  }
  
  sort(edges.begin(), edges.end());

  UnionFind uf(N);
  long long totalCost = 0;
  for (const auto &[cost, u, v] : edges) {
    if (uf.Union(u, v)) {
      totalCost += cost;
    }
  }

  cout << totalCost;

  return 0;
}