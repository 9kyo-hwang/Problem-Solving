#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;

  int i = 1;
  while(true) {
    string num = to_string(i);
    N -= num.length();
    if(N <= 0) {
      cout << num[num.length() - 1 + N]; // N: -(num.length() - 1) ~ 0
      break;
    }
    i++;
  }
  return 0;
}