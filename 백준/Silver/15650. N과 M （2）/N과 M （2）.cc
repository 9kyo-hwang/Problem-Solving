#include <cstdio>

int N, M;
bool include[8];

void backtracking(int index = 0, int count = 0) { 
  if (index == N) {
    if (count != M) {
      return;
    }

    for (int i = 0; i < 8; ++i) {
      if (include[i]) {
        printf("%d ", i + 1);
      }
    }
    printf("\n");
    return;
  }

  include[index] = true;
  backtracking(index + 1, count + 1);
  include[index] = false;
  backtracking(index + 1, count);
}

int main() {
  scanf(" %d %d", &N, &M);
  backtracking();

  return 0;
}