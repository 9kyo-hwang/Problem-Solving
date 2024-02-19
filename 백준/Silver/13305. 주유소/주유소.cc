#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> distances(N, 0), prices(N);
  for(int i = 0; i < N - 1; i += 1) {
    cin >> distances[i];
  }
  for(int i = 0; i < N; i += 1) {
    cin >> prices[i];
  }

  int price = prices[0];
  ll answer = distances[0] * price;

  for(int i = 1; i < N; i += 1) {
    if(price >= prices[i]) {
      price = prices[i];
    }

    answer += price * distances[i];
  }

  cout << answer;

  return 0;
}