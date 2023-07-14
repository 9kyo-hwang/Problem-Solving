#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string str;
  cin >> str;

  istringstream ss(str);
  string buffer;

  string answer;
  bool flag = false;
  while(getline(ss, buffer, '.')) {
    if(buffer.empty()) {
      answer += ".";
    } else if(buffer.length() % 2 == 1) {
      cout << -1;
      flag = true;
      break;
    } else {
      int strlen = buffer.length();
      for(int i = 0; i < strlen / 4; i++) {
        answer += "AAAA";
      }
      if(strlen % 4) {
        answer += "BB";
      }
      answer += ".";
    }
  }

  if(str.back() != '.') {
    answer.pop_back();
  }
    
  if(!flag) {
    cout << answer;
  }

  return 0;
}