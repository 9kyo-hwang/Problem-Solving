#include <cstdio>

#define MAX 10

int answer[MAX];

int main() {
  int N;
  scanf(" %d", &N);

  for (int height = 1; height <= N; ++height) {
    int num;
    scanf(" %d", &num);

    for (int i = 0; i < N; i++) {
      if (num == 0 && answer[i] == 0) {
        answer[i] = height;
        break;
      }

      if (answer[i] == 0) {
        --num;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%d ", answer[i]);
  }

  return 0;
}