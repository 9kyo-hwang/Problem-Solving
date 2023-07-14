#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> C(N, 0);
  for(auto &c : C)
    cin >> c;

  sort(C.begin(), C.end());

  int answer = 0;
  int i;
  for(i = N - 1; i - 2 >= 0; i -= 3) {
    answer += C[i] + C[i-1];
  }

  if(i == 0) {
    answer += C[i];
  } else if(i == 1) {
    answer += C[i] + C[i - 1];
  }

  cout << answer;
  return 0;
}