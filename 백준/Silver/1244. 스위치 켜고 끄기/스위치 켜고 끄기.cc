#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<bool> v(N + 1);
  for (int i = 1; i <= N; i++) {
    int state;
    cin >> state;

    v[i] = state;
  }

  int students; cin >> students;
  while (students--) {
    int sex, num;
    cin >> sex >> num;

    if (sex == 1) {
      for (int i = num; i <= N; i += num) {
        v[i] = !v[i];
      }
    } else if (sex == 2) {
      v[num] = !v[num];

      int begin = num - 1, end = num + 1;
      while ((begin >= 1 && end <= N) && v[begin] == v[end]) {
        v[begin] = !v[begin];
        v[end] = !v[end];

        begin--;
        end++;
      }
    }
  }

  int j;
  for (int i = 1; i <= N; i++) {
    j = i % 20;
    cout << v[i] << " ";
    if (j == 0) {
      cout << "\n";
    }
  }

  return 0;
}