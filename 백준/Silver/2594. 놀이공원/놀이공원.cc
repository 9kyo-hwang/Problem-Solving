#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  vector<pair<int, int>> table(N);
  for (auto &[begin, end] : table) {
    cin >> begin >> end;
    begin = (begin / 100) * 60 + begin % 100 - 10;
    end = (end / 100) * 60 + end % 100 + 10;
  }

  sort(table.begin(), table.end());
  int answer = 0;
  int time = 600;
  for (const auto &[begin, end] : table) {
    answer = max(answer, max(begin - time, 0));
    if(end > time)
      time = end;
  }
  answer = max(answer, max(1320 - time, 0));

  cout << answer;

  return 0;
}