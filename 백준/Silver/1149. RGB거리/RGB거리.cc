#include <cstdio>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
  int N;
  scanf(" %d", &N);

  int R, G, B;
  for (int i = 0; i < N; ++i) {
    int r, g, b;
    scanf(" %d %d %d", &r, &g, &b);

    if (i == 0) {
      R = r;
      G = g;
      B = b;

      continue;
    }

    int t1 = MIN(G, B) + r;
    int t2 = MIN(R, B) + g;
    int t3 = MIN(R, G) + b;

    R = t1, G = t2, B = t3;
  }
    
  printf("%d", MIN(R, MIN(G, B)));

  return 0;
}