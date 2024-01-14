#include <cstdio>

char tree[27][2];

void traversal(int mode, int node = 0) {
  if (node + 'A' == '.') {
    return;
  }

  if (mode == 0) {
    printf("%c", node + 'A');
    traversal(mode, tree[node][0] - 'A');
    traversal(mode, tree[node][1] - 'A');
  } else if (mode == 1) {
    traversal(mode, tree[node][0] - 'A');
    printf("%c", node + 'A');
    traversal(mode, tree[node][1] - 'A');
  } else {
    traversal(mode, tree[node][0] - 'A');
    traversal(mode, tree[node][1] - 'A');
    printf("%c", node + 'A');
  }
}

int main() {
  int N;
  scanf(" %d", &N);

  while (N--) {
    char ch, l, r;
    scanf(" %c %c %c", &ch, &l, &r);
    tree[ch - 'A'][0] = l;
    tree[ch - 'A'][1] = r;
  }

  for (int i = 0; i < 3; ++i) {
    traversal(i);
    printf("\n");
  }

  return 0;
}