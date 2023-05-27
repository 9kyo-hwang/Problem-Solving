#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  queue<int> q;
  for(int i = 1; i <= N; i++)
    q.emplace(i);

  vector<int> result;
  int step = 0;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    if(step + 1 == K)
      result.emplace_back(cur);
    else
      q.emplace(cur);

    step = (step + 1) % K;
  }

  int back = result.back();
  result.pop_back();

  cout << "<";
  for(const auto i : result)
    cout << i << ", ";
  cout << back << ">";

  return 0;
}