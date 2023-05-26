#include <iostream>
#include <vector>

using namespace std;

int N, S, count = 0;
vector<int> num;
vector<bool> include;

void PowerSet(const int& max_select, int cur_select = 0, int index = 0) {
  if(cur_select == max_select) {
    int cur_sum = 0;
    for(int i = 0; i <= index; i++)
      if(include[i])
        cur_sum += num[i];

    if(cur_sum == S)
      count++;

    return;
  }

  if(index >= N)
    return;

  include[index] = true;
  PowerSet(max_select, cur_select + 1, index + 1);
  include[index] = false;
  PowerSet(max_select, cur_select, index + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> S;
  num = vector<int>(N);
  for(auto &i : num)
    cin >> i;
  include = vector<bool>(N, false);

  for(int k = 1; k <= N; k++) {
    PowerSet(k);
  }

  cout << count;

  return 0;
}