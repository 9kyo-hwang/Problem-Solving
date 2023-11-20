#include <cstdio>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main() { 
  int N, M;
  scanf("%d %d", &N, &M);

  int min_set = 1001, min_each = 1001;
  for (int i = 0; i < M; i++) {
    int set, each;
    scanf(" %d %d", &set, &each);

    min_set = MIN(min_set, set);
    min_each = MIN(min_each, each);
  }

  if (min_set > min_each * 6) {
    printf("%d", min_each * N);
    return 0;
  }

  int answer = min_set * (N / 6);
  if (min_each * (N % 6) > min_set) {
    answer += min_set;
  } else {
    answer += min_each * (N % 6);
  }
  printf("%d", answer);

  return 0;
}