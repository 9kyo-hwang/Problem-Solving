#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<char, int> map = {
      {'H', 1},
      {'C', 12},
      {'O', 16},
  };

  string str;
  cin >> str;

  vector<int> stack;
  for (const auto &ch : str) {
    if (ch == '(') {
      stack.emplace_back(-1);
    } else if (map.find(ch) != map.end()) {
      stack.emplace_back(map[ch]);
    } else if (isdigit(ch)) {
      int tmp = stack.back() * (ch - '0');
      stack.pop_back();
      stack.emplace_back(tmp);
    } else if (ch == ')') {
      int num = 0;
      while (stack.back() != -1) {
        num += stack.back();
        stack.pop_back();
      }
      stack.pop_back();
      stack.emplace_back(num);
    }
  }

  int answer = 0;
  while (!stack.empty()) {
    answer += stack.back();
    stack.pop_back();
  }

  cout << answer;

  return 0;
}