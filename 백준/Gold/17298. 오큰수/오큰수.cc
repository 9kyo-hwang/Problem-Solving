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

  vector<int> stack, answer;
  for (auto it = NGE.rbegin(); it != NGE.rend(); ++it) {
    while (!stack.empty() && *it >= stack.back()) {
      stack.pop_back();
    }


    if (stack.empty()) {
      answer.emplace_back(-1);
    } else {
      answer.emplace_back(stack.back());
    }

    stack.emplace_back(*it);
  }

  for (auto it = answer.rbegin(); it != answer.rend(); ++it) {
    cout << *it << " ";
  }

  return 0;
}