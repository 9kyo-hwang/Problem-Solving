#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<pair<int, int>> v(N);
  for (int i = 0; i < N; i++) {
	v[i].first = i; // index
	cin >> v[i].second; // data
  }

  // sorting by data
  sort(v.begin(), v.end(),
	   [](const pair<int, int> &p, const pair<int, int> &q) {
		 return p.second < q.second;
	   });

  vector<int> compress(N);

  int compressed_data = 0;
  int prev_data = v[0].second;
  for (const auto &[index, data] : v) {
	if (prev_data != data) compressed_data++;
	prev_data = data;
	compress[index] = compressed_data;
  }

  for (const auto data : compress)
	cout << data << " ";

  return 0;
}