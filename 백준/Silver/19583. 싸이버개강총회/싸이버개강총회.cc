#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  unordered_map<string, int> log;

  string S, E, Q;
  cin >> S >> E >> Q;

  int s = stoi(S.substr(0, 2)) * 100 + stoi(S.substr(3, 5));
  int e = stoi(E.substr(0, 2)) * 100 + stoi(E.substr(3, 5));
  int q = stoi(Q.substr(0, 2)) * 100 + stoi(Q.substr(3, 5));

  int count = 0;
  string T, nickname;
  while(cin >> T >> nickname) {
    int t = stoi(T.substr(0, 2)) * 100 + stoi(T.substr(3, 5));

    if(t <= s && log[nickname] == 0) {
      log[nickname] = 1;
    }
    else if(e <= t && t <= q && log[nickname] == 1) {
      log[nickname] = 2;
      count++;
    }
  }

  cout << count;
  return 0;
}