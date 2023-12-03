#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> cols;

bool promising(int level) {
  for (int i = 1; i <= level - 1; i++) {
    if (cols[i] == cols[level]) {
      return false;
    } else if (level - i == abs(cols[level] - cols[i])) {
      return false;
    }
  }
  return true;
}

int queens(int level = 0) {
  if (!promising(level)) {
    return 0;
  } else if (level == N) {
    return 1;
  } else {
    int count = 0;
    for (int i = 1; i <= N; i++) {
      cols[level + 1] = i;
      count += queens(level + 1);
    }
    return count;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  cols.assign(N + 1, 0);

  cout << queens();

  return 0;
}