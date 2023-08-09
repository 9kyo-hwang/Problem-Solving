#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int QuickSelect(const vector<int> &array, int k) {
  if (array.size() <= 1)
    return array[0];

  int pivot = array[array.size() / 2];
  vector<int> left, mid, right;
  copy_if(array.begin(), array.end(), back_inserter(left), [&](int x) { return x < pivot; });
  copy_if(array.begin(), array.end(), back_inserter(mid), [&](int x) { return x == pivot; });
  copy_if(array.begin(), array.end(), back_inserter(right), [&](int x) { return x > pivot; });

  if (k < left.size()) {
    return QuickSelect(left, k);
  } else if (k < left.size() + mid.size()) {
    return mid[0];
  } else {
    return QuickSelect(right, k - (left.size() + mid.size()));
  }
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;
  for (const auto &command : commands) {
    int i = command[0], j = command[1], k = command[2];
    answer.emplace_back(QuickSelect(vector<int>(&array[i - 1], &array[j]), k - 1));
  }
  return answer;
}