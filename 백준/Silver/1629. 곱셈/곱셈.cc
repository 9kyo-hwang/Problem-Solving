#include <cstdio>

using ll = long long;

int main() {
  ll A, B, C;
  scanf(" %lld %lld %lld", &A, &B, &C);

  ll answer = 1;
  while (B > 0) {
    if (B % 2 == 1) {
      answer = (answer * A) % C;
    }

    A = (A * A) % C;
    B /= 2;
  }

  printf("%lld", answer);

  return 0;
}