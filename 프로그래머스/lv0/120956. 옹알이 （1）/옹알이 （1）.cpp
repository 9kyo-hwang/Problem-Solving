#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const vector<string> &v = {"aya", "ye", "woo", "ma"};
vector<bool> used(4, false);
unordered_map<string, bool> map;

void dfs(const string &str, int current_index) {
  map[str] = true;

  for (int i = 0; i < 4; i++) {
    if (current_index == i || used[i])
      continue;

    used[i] = true;
    dfs(str + v[i], i);
    used[i] = false;
  }
}

int solution(vector<string> babbling) {
  for (int i = 0; i < 4; i++) {
    used[i] = true;
    dfs(v[i], i);
    used[i] = false;
  }

  int answer = 0;
  for (const auto &str : babbling) {
    answer += map[str];
  }
  return answer;
}