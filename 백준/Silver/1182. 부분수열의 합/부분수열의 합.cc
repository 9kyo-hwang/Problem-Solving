#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> num;

int PowerSet(int index = 0, int sum = 0) {
  if(index >= N)
    return sum == S;
  return PowerSet(index + 1, sum + num[index]) + PowerSet(index + 1, sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> S;
  num = vector<int>(N);
  for(auto &i : num)
    cin >> i;

  int count = PowerSet();
  if(S == 0)
    --count;
  cout << count;

  return 0;
}