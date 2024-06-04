#include <stdio.h>

int m, q, n, x;
int f[19][200001];

int main() {
    scanf(" %d", &m);
    
    for(int x = 1; x <= m; ++x) {
        scanf(" %d", &f[0][x]);
    }
    
    for(int n = 1; n <= 18; ++n) {
        for(int x = 1; x <= m; ++x) {
            f[n][x] = f[n - 1][f[n - 1][x]];
        }
    }
    
    scanf(" %d", &q);
    while(q--) {
        scanf(" %d%d", &n, &x);
        for(int i = 0; i <= 18; ++i) {
            if(n & (1 << i)) {
                x = f[i][x];
            }
        }
        printf("%d\n", x);
    }
    
    return 0;
}