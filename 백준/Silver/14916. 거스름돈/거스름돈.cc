#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  if(n == 1 || n == 3) {
    cout << -1;
    return 0;
  }

  int count = 0;

  while(n % 5) {
    n -= 2;
    count += 1;
  }

  count += n / 5;

  cout << count;

  return 0;
}