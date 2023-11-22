#include <iostream>
#include <vector>

using namespace std;

int main() { 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  
  vector<int> NGE(N);
  for (int &i : NGE) cin >> i;

  vector<int> stack, answer(N);
  int index = 0;
  for (auto it = NGE.rbegin(); it != NGE.rend(); ++it) {
    while (!stack.empty() && *it >= stack.back()) {
      stack.pop_back();
    }


    if (stack.empty()) {
      answer[index++] = -1;
    } else {
      answer[index++] = stack.back();
    }

    stack.emplace_back(*it);
  }

  for (int i = index - 1; i >= 0; i--) {
    cout << answer[i] << " ";
  }

  return 0;
}