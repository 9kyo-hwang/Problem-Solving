#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<string> v(N);
  for(auto& str : v)
    cin >> str;

  sort(v.begin(), v.end(), [](const string& a, const string& b) {
    return a + b > b + a;
  });

  string str;
  if(v[0] == "0") {
    str = "0";
  } else {
    for(const auto& num : v)
      str += num;
  }

  cout << str;

  return 0;
}