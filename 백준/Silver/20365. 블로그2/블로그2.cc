#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;

  int state = 0; // 0: init, 1: red, 2: blue
  int r = 0, b = 0;
  while(N--) {
    char ch;
    scanf(" %1c", &ch);

    if(state == 0) {
      if(ch == 'R') {
        state = 1;
        r += 1;
      } else if(ch == 'B') {
        state = 2;
        b += 1;
      }
      continue;
    }

    if(ch == 'R' && state == 2) {
      state = 1;
      r += 1;
    } else if(ch == 'B' && state == 1) {
      state = 2;
      b += 1;
    }
  }

  cout << min(r, b) + 1;

  return 0;
}