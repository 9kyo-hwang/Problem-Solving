#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  vector<string> v(N);
  for (string &str : v)
    cin >> str;

  sort(v.begin(), v.end(), [](const string &a, const string &b) {
    return a + b > b + a;
  });

  string answer;
  int repeat_cnt = K - N;
  string repeat_num = "0";

  for (const string &num : v) {
    if (num.length() > repeat_num.length() || num.length() == repeat_num.length() && num > repeat_num)
      repeat_num = num;
  }

  bool flag = false;
  for (const string &num : v) {
    if (!flag && num == repeat_num) {
      while (repeat_cnt--)
        answer += num;
      flag = true;
    }
    answer += num;
  }

  cout << answer;

  return 0;
}