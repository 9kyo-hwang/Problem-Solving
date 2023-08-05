#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  unordered_map<int, string> title_name;
  vector<int> title_score;
  while (N--) {
    string title;
    int limit;

    cin >> title >> limit;
    if (title_name.find(limit) == title_name.end()) {
      title_name[limit] = title;
      title_score.emplace_back(limit);
    }
  }

  sort(title_score.begin(), title_score.end());

  while (M--) {
    int score;
    cin >> score;

    int index = lower_bound(title_score.begin(), title_score.end(), score) - title_score.begin();
    cout << title_name[title_score[index]] << "\n";
  }

  return 0;
}