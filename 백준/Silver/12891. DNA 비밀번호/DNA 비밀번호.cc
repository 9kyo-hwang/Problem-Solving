#include <cstdio>

#define MAX 1000001

int counts[91];
int satisfied[91];

inline bool is_satisfied() {
  return counts['A'] >= satisfied['A'] && counts['C'] >= satisfied['C'] &&
         counts['G'] >= satisfied['G'] && counts['T'] >= satisfied['T'];
}

int main() {
  int S, P;
  scanf(" %d %d", &S, &P);

  char str[MAX];
  scanf(" %s", str);

  for (int i = 0; i < P; i++) {
    counts[str[i]] += 1;
  }

  scanf(" %d %d %d %d", &satisfied['A'], &satisfied['C'], &satisfied['G'],
        &satisfied['T']);

  int answer = is_satisfied();

  for (int i = 0, j = P; j < S; i++, j++) {
    counts[str[i]] -= 1;
    counts[str[j]] += 1;

    answer += is_satisfied();
  }

  printf("%d", answer);

  return 0;
}