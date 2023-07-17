#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> drinks(N);
  for(int &i : drinks)
    cin >> i;

  sort(drinks.begin(), drinks.end());

  deque<double> d(drinks.begin(), drinks.end());

  while(d.size() >= 2) {
    double front = d.front();
    double back = d.back();
    d.pop_front(); d.pop_back();

    d.emplace_back(back + front / 2);
  }

  cout << fixed;
  cout.precision(5);
  cout << d.front();

  return 0;
}