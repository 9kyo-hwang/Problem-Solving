#include <iostream>
#include <vector>

using namespace std;

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

  int answer = 0;
  int index = 0;
  while(index < N) {
    int start = index;
    int price = prices[index];
    index += 1;

    while(price <= prices[index]) {
      index += 1;
    }

    for(int i = start; i < index; i += 1) {
      answer += price * distances[i];
    }
  }

  cout << answer;

  return 0;
}