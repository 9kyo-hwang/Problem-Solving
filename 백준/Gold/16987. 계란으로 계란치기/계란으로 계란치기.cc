#include <cstdio>

int N;
int eggs[8][2];

int backtracking(int current = 0, int broken = 0) {
  if (current == N) {
    return broken;
  } else if (eggs[current][0] <= 0 || broken == N - 1) {
    return backtracking(current + 1, broken);
  } else {
    int count = 0;
    for (int next = 0; next < N; next++) {
      if (current == next || eggs[next][0] <= 0) {
        continue;
      }

      eggs[current][0] -= eggs[next][1];
      eggs[next][0] -= eggs[current][1];
      
      int ret = backtracking(
          current + 1, 
          broken + (eggs[current][0] <= 0) + (eggs[next][0] <= 0)
      );

      if (ret > count) {
        count = ret;
      }

      eggs[current][0] += eggs[next][1];
      eggs[next][0] += eggs[current][1];
    }
    return count;
  }
}

int main() {
  scanf(" %d", &N);

  for (int i = 0; i < N; i++) {
    scanf(" %d %d", &eggs[i][0], &eggs[i][1]);
  }

  printf("%d", backtracking());
  return 0;
}