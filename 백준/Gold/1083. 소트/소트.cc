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

  vector<int> v(N);
  for (int &i : v)
    cin >> i;

  int S;
  cin >> S;

  for (int i = 0; i < N - 1 && S > 0; i++) {
    int cnt = 0;
    int max_index = i;

    for(int j = i + 1; j < N && cnt < S; j++, cnt++) {
      if(v[j] > v[max_index]) {
        max_index = j;
      }
    }

    S -= (max_index - i);
    while(max_index > i) {
      swap(v[max_index - 1], v[max_index]);
      max_index--;
    }
  }

  for (const auto &i : v)
    cout << i << " ";

  return 0;
}