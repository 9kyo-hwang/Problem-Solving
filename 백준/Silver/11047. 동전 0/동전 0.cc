#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  vector<int> coin_types(N, 0);
  for(int i = N - 1; i >= 0; i -= 1) {
    cin >> coin_types[i];
  }

  int count = 0;
  for(const auto &coin : coin_types) {
    count += K / coin;
    K %= coin;
  }

  cout << count;

  return 0;
}