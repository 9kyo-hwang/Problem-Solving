#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;

  while(T--) {
    string p; cin >> p;
    int n; cin >> n;
    string arr; cin >> arr;

    deque<int> dq;
    string new_arr = string(arr.begin() + 1, arr.end() - 1);
    istringstream ss(new_arr);
    string buffer;
    while(getline(ss, buffer, ','))
      dq.emplace_back(stoi(buffer));

    bool reverse = false;
    bool error = false;
    for(const auto& ch : p) {
      if(ch == 'R') {
        reverse = !reverse;
      } else if(ch == 'D') {
        if(dq.empty()) {
          cout << "error\n";
          error = true;
          break;
        } else {
          reverse ? dq.pop_back() : dq.pop_front();
        }
      }
    }

    if(error)
      continue;

    cout << "[";
    if(!dq.empty()) {
      int end;
      if(reverse) {
        end = dq.front();
        dq.pop_front();
        while(!dq.empty()) {
          cout << dq.back() << ",";
          dq.pop_back();
        }
      } else {
        end = dq.back();
        dq.pop_back();
        while(!dq.empty()) {
          cout << dq.front() << ",";
          dq.pop_front();
        }
      }
      cout << end;
    }
    cout << "]\n";
  }

  return 0;
}