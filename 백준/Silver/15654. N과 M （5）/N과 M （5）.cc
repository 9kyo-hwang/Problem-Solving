#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums, include;
vector<int> ans;

void backtracking(int count = 0) {
  if (count == M) {
    for (const auto &i : ans) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; ++i) {
    if (include[i] == 1) {
      continue;
    }

    include[i] = 1;
    ans.emplace_back(nums[i]);
    backtracking(count + 1);
    include[i] = 0;
    ans.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  nums.resize(N);
  for (int &i : nums) {
    cin >> i;
  }
  sort(nums.begin(), nums.end());

  include.assign(N, 0);

  backtracking();

  return 0;
}