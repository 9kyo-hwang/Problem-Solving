#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX = 1'000'000'001;

struct Group {
  int m_min_num = MAX;
  vector<int> m_v;
};

int N, M, G, K;
vector<Group> v;

int RangeQuery(const int i, const int j) {
  const int i_group = i / M;
  const int i_index = i % M;
  const int j_group = j / M;
  const int j_index = j % M;

  int min_num = MAX;

  int index = i_index;
  if (i_group == j_group) {
    while (index <= j_index) {
      min_num = min(min_num, v[i_group].m_v[index]);
      index++;
    }
    return min_num;
  }

  while (index < M) {
    min_num = min(min_num, v[i_group].m_v[index]);
    index++;
  }

  int group = i_group + 1;
  while (group < j_group) {
    min_num = min(min_num, v[group].m_min_num);
    group++;
  }

  index = 0;
  while (index <= j_index) {
    min_num = min(min_num, v[j_group].m_v[index]);
    index++;
  }

  return min_num;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> K;

  M = int(floor(sqrt(N)));
  G = int(ceil(double(N) / M));

  v = vector<Group>(G);
  for (auto &[m_min, m_v] : v) {
    if (N > M) m_v = vector<int>(M);
    else m_v = vector<int>(N);

    for (int &i : m_v) {
      cin >> i;
      m_min = min(m_min, i);
    }

    N -= M;
  }

  while (K--) {
    int a, b;
    cin >> a >> b;
    cout << RangeQuery(a - 1, b - 1) << "\n";
  }

  return 0;
}