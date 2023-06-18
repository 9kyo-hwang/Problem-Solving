#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class UnionFind {
 public:
  explicit UnionFind(int size) {
    p_ = vector<int>(size);
    for (int i = 0; i < size; i++)
      p_[i] = i;
    size_ = vector<int>(size, 1);
  }
  ~UnionFind() = default;

  bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v) // u, v is cycled
      return false;

    if (size_[u] > size_[v]) {
      p_[v] = u;
      size_[u] += size_[v];
    } else {
      p_[u] = v;
      size_[v] += size_[v];
    }

    return true; // successfully union
  }

 private:
  vector<int> p_, size_;

  int Find(int x) {
    while (x != p_[x]) {
      p_[x] = p_[p_[x]];
      x = p_[x];
    }

    return p_[x];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  UnionFind uf(N + 1);

  int M;
  cin >> M;

  vector<tuple<int, int, int>> edges(M);

  for (auto &[dist, src, dst] : edges)
    cin >> src >> dst >> dist;

  sort(edges.begin(), edges.end());

  int cost = 0;
  vector<int> costs;
  for (const auto &[dist, src, dst] : edges) {
    if (uf.Union(src, dst)) {
      cost += dist;
      costs.emplace_back(dist);
    }
  }

  cout << cost - costs.back();

  return 0;
}