#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int N, M;
  cin >> N >> M;
  
  unordered_map<string, int> m; // string to index
  vector<string> v(N + 1); // index to string

  string str;
  for (int i = 1; i <= N; i++) {
	cin >> str;
    m[str] = i;
    v[i] = str;
  }

  while (M--) {
    cin >> str;
    if (isdigit(str[0])) {
      cout << v[stoi(str)];
    } else {
      cout << m[str];
    }
    cout << "\n";
  }

  return 0;
}